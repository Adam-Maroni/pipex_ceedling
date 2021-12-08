#ifdef TEST

#include <string.h>
#include "unity.h"
#include "extract.h"

#define PROG "./pipex"
#define FILE1 "inFile"
#define CMD1 "ls"
#define CMD1ARGS "-l"
#define CMD2 "wc"
#define CMD2ARGS "-l -m -c"
#define FILE2 "outFile"



int argc = 5;
char **argv;
char **envp;

void setUp(void)
{
	argv = (char**)calloc(argc + 1, sizeof(char*));
	argv[0] = strdup(PROG);
	argv[1] = strdup(FILE1);
	argv[2] = strdup(CMD1 " " CMD1ARGS);
	argv[3] = strdup(CMD2 " " CMD2ARGS);
	argv[4] = strdup(FILE2);
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
}
void test_ft_extract_cmd_should_return_empty_when_empty_is_passed(void)
{
	char *cmd = NULL;
	cmd = ft_extract_cmd("");
	TEST_ASSERT_EQUAL_STRING("", cmd);
	if (cmd);
		free(cmd);
}
void test_ft_extract_cmd_should_return_cmd(void)
{
	char *cmd = ft_extract_cmd(argv[2]);
	TEST_ASSERT_EQUAL_STRING(CMD1, cmd);
	if (cmd)
		free(cmd);
	cmd = ft_extract_cmd(argv[3]);
	TEST_ASSERT_EQUAL_STRING(CMD2, cmd);
	if (cmd)
		free(cmd);
}
/* ft_extract_cmd_args */
void test_ft_extract_cmd_args_should_return_null_when_null_passed(void)
{
	TEST_ASSERT_NULL(ft_extract_cmd_args(NULL));
}
void test_ft_extract_cmd_args_should_return_null_when_no_args_is_passed(void)
{
	TEST_ASSERT_NULL(ft_extract_cmd_args("cat"));
	TEST_ASSERT_NULL(ft_extract_cmd_args("cat   "));
}
void test_ft_extract_cmd_args_should_return_empty_when_empty_is_passed(void)
{
	char *cmd_args = NULL;
	cmd_args = ft_extract_cmd_args("");
	TEST_ASSERT_EQUAL_STRING("", cmd_args);
	if (cmd_args);
		free(cmd_args);
}
void test_ft_extract_cmd_args_should_return_cmd_args(void)
{
	char *cmd_args = ft_extract_cmd_args(argv[2]);
	TEST_ASSERT_EQUAL_STRING(CMD1ARGS, cmd_args);
	if (cmd_args)
		free(cmd_args);
	cmd_args = ft_extract_cmd_args(argv[3]);
	TEST_ASSERT_EQUAL_STRING(CMD2ARGS, cmd_args);
	if (cmd_args)
		free(cmd_args);
}
#endif // TEST
