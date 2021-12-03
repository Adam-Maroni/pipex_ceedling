#ifdef TEST

#include "unity.h"
#include <string.h>
#include "listpipex.h"
TEST_FILE("../src/extract.c")


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
}

void tearDown(void)
{
	for (int i = 0; i < argc ; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

void test_ft_init_pipex_list_should_initialize_the_list(void)
{
	t_list_pipex *list = ft_init_pipex_list(argc, argv);
	TEST_ASSERT_EQUAL_STRING(FILE1, list->content);
	TEST_ASSERT_EQUAL_STRING(CMD1, list->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD1ARGS, list->next->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD2, list->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD2ARGS, list->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(FILE2, list->next->next->next->next->next->content);
	TEST_ASSERT_NULL(list->next->next->next->next->next->next);
	ft_free_pipex_list(&list);
}

#endif // TEST
