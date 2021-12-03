#ifdef TEST

#include "unity.h"
#include "parser.h"
#include <string.h>

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


/* ft_return_cmd_binary_absolute_path */
void test_ft_return_cmd_binary_absolute_path(void)
{
	char *rt = ft_return_cmd_binary_absolute_path("wc", envp[2]);
	TEST_ASSERT_TRUE(access(rt, F_OK) == 0);
	if (rt)
		free(rt);
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

