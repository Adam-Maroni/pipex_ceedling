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
#define CMD3 "ps"
#define CMD4 "du"
#define FILE2 "outFile"

int argc = 7;
char **argv;
char **envp;

void setUp(void)
{
	argv = (char**)calloc(argc + 1, sizeof(char*));
	argv[0] = strdup(PROG);
	argv[1] = strdup(FILE1);
	argv[2] = strdup(CMD1 " " CMD1ARGS);
	argv[3] = strdup(CMD2 " " CMD2ARGS);
	argv[4] = strdup(CMD3);
	argv[5] = strdup(CMD4);
	argv[6] = strdup(FILE2);
}

void tearDown(void)
{
	for (int i = 0; i < argc ; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

/* ft_init_pipex_list */
void test_ft_init_pipex_list_should_return_null_if_argv_is_null(void)
{
	TEST_ASSERT_NULL(ft_init_pipex_list(argc, NULL));
}
void test_ft_init_pipex_list_should_return_null_if_argc_below_2(void)
{
	for (int i = 1; i > -10 ; i--)
		TEST_ASSERT_NULL(ft_init_pipex_list(i, argv));
}
void test_ft_init_pipex_list_should_initialize_the_list(void)
{
	t_list_pipex *list = NULL;

	list = ft_init_pipex_list(argc, argv);
	TEST_ASSERT_EQUAL_STRING(CMD1, list->content);
	TEST_ASSERT_EQUAL_STRING(CMD1ARGS, list->next->content);
	TEST_ASSERT_EQUAL_STRING(FILE1, list->next->next->content);
	TEST_ASSERT_EQUAL_STRING("|", list->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD2, list->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD2ARGS, list->next->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING("|", list->next->next->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD3, list->next->next->next->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING("|", list->next->next->next->next->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(CMD4, list->next->next->next->next->next->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING("|", list->next->next->next->next->next->next->next->next->next->next->content);
	TEST_ASSERT_EQUAL_STRING(FILE2, list->next->next->next->next->next->next->next->next->next->next->next->content);
	TEST_ASSERT_NULL(list->next->next->next->next->next->next->next->next->next->next->next->next);
	ft_free_pipex_list(&list);

	int new_argc = 3;
	char **new_argv = (char**)calloc(new_argc, sizeof(*new_argv));
	new_argv[0] = strdup("./pipex");
	new_argv[1] = strdup("inFile");
	new_argv[2] = strdup("cat -ne");
	list = ft_init_pipex_list(new_argc, (char**)new_argv);
	//test
	TEST_ASSERT_EQUAL_STRING("cat", list->content);
	TEST_ASSERT_EQUAL_STRING("-ne", list->next->content);
	TEST_ASSERT_EQUAL_STRING("inFile", list->next->next->content);
	TEST_ASSERT_NULL(list->next->next->next);
	//free
	for(int i = 0; i < new_argc; i++)
		if (new_argv[i])
			free(new_argv[i]);
	free(new_argv);
	ft_free_pipex_list(&list);
}

#endif // TEST
