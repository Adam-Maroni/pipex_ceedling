#ifdef TEST

#include <string.h>
#include "unity.h"
#include "extract.h"

int argc = 5;
char **argv;
char **envp;

void setUp(void)
{
	argv = (char**)calloc(argc + 1, sizeof(char*));
	argv[0] = strdup("./pipex");
	argv[1] = strdup("inFile");
	argv[2] = strdup("ls -l");
	argv[3] = strdup("wc -l -m -c");
	argv[4] = strdup("outFile");
	argv[5] = NULL;

	envp = (char**)calloc(argc + 1, sizeof(char*));
	envp[0] = strdup("envp0");
	envp[1] = strdup("envp1");
	envp[2] = strdup("PATH=/mnt/nfs/homes/amaroni/.brew/bin:/mnt/nfs/homes/amaroni/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[3] = strdup("envp3");
	envp[4] = strdup("envp4");
	envp[5] = NULL;
}

void tearDown(void)
{
	for (int i = 0; i < argc ; i++)
	{
		free(argv[i]);
		free(envp[i]);
	}
	free(argv);
	free(envp);
}

/* ft_extract_envar_path */
void test_ft_extract_envar_path_should_return_null_if_path_not_found(void)
{
	free(envp[2]);
	envp[2] = strdup("envp2");
	TEST_ASSERT_NULL(ft_extract_envar_path(envp));
}
void test_ft_extract_envar_path_should_return_path_string_if_found(void)
{
	char *rt = NULL;
	rt = ft_extract_envar_path(envp);
	TEST_ASSERT_NOT_NULL(rt);
	TEST_ASSERT_EQUAL_STRING(envp[2],rt);
}

/* ft_extract_cmd */
void test_ft_extract_cmd_should_return_null_when_empty_or_null_passed(void)
{
	TEST_ASSERT_NULL(ft_extract_cmd(NULL));
	TEST_ASSERT_NULL(ft_extract_cmd(""));
}
void test_ft_extract_cmd_should_return_cmd(void)
{
	char *cmd = ft_extract_cmd(argv[2]);
	TEST_ASSERT_EQUAL_STRING("ls", ft_extract_cmd(argv[2]));
	if (cmd)
		free(cmd);
	cmd = ft_extract_cmd(argv[2]);
	TEST_ASSERT_EQUAL_STRING("wc", ft_extract_cmd(argv[3]));
	if (cmd)
		free(cmd);
}

/* ft_extract_cmd_args */
void test_ft_extract_cmd_args_should_return_null_when_empty_or_null_passed(void)
{
	TEST_ASSERT_NULL(ft_extract_cmd_args(NULL));
	TEST_ASSERT_NULL(ft_extract_cmd_args(""));
}
void test_ft_extract_cmd_args_should_return_cmd_args(void)
{
	char *cmd_args = ft_extract_cmd_args(argv[2]);
	TEST_ASSERT_EQUAL_STRING("-l", ft_extract_cmd_args(argv[2]));
	if (cmd_args)
		free(cmd_args);
	cmd_args = ft_extract_cmd_args(argv[2]);
	TEST_ASSERT_EQUAL_STRING("-l -m -c", ft_extract_cmd_args(argv[3]));
	if (cmd_args)
		free(cmd_args);
}

#endif // TEST
