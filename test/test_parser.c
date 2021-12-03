#ifdef TEST

#include "unity.h"
#include "parser.h"
#include <string.h>

int argc = 5;
char **argv;
char **envp;
char **cmd;

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


	cmd = (char**)calloc(argc + 1, sizeof(char*));
	cmd[0] = strdup("wc");
	cmd[1] = strdup("cat");
	cmd[2] = strdup("ls");
	cmd[3] = strdup("mkdir");
	cmd[4] = strdup("mv");
	cmd[5] = NULL;
}

void tearDown(void)
{
	for (int i = 0; i < argc ; i++)
	{
		free(argv[i]);
		free(envp[i]);
		free(cmd[i]);
	}
	free(argv);
	free(envp);
	free(cmd);
}


/* ft_return_cmd_absolute_path */
void test_ft_return_cmd_absolute_path_should_return_valid_binary(void)
{
	for (int i=0; cmd[i]; i++)
	{
		char *rt = ft_return_cmd_absolute_path(cmd[i], envp[2]);
		TEST_ASSERT_TRUE(access(rt, F_OK) == 0);
		if (rt)
			free(rt);
	}
}


/* ft_parsing */
void test_ft_parsing_should_return_null_if_argc_is_not_5(void)
{
	for (int i = 0; i <= 4 ; i++)
		TEST_ASSERT_NULL(ft_parsing(i, argv, envp));
	TEST_ASSERT_NOT_NULL(ft_parsing(5, argv, envp));
	for (int i = 6; i <= 20 ; i++)
		TEST_ASSERT_NULL(ft_parsing(i, argv, envp));
}
/*--------------------------------------------------*/

#endif // TEST

