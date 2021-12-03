#ifdef TEST

#include "unity.h"
#include <string.h>
#include "listpipex.h"
TEST_FILE("../src/extract.c")

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

void test_ft_init_pipex_list_should_initialize_the_list(void)
{
	t_list_pipex *list = ft_init_pipex_list(argv, NULL);
	TEST_ASSERT_EQUAL_STRING("inFile", list->file);
	TEST_ASSERT_EQUAL_STRING("ls", list->cmd_binary);
	TEST_ASSERT_EQUAL_STRING("-l", list->cmd_args);
	TEST_ASSERT_EQUAL_STRING("outFile", list->next->file);
	TEST_ASSERT_EQUAL_STRING("wc", list->next->cmd_binary);
	TEST_ASSERT_EQUAL_STRING("-l -m -c", list->next->cmd_args);
	TEST_ASSERT_NULL(list->next->next);
	ft_free_pipex_list(&list);
}

#endif // TEST
