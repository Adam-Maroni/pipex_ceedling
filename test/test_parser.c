#ifdef TEST

#include "unity.h"

#include "parser.h"
#include <string.h>

#define ARGC 5
#define MAX_STR_LEN 100
//char argv[ARGC][MAX_STR_LEN] = {"pipex", "inFile", "cat", "wc -l", "outFile"};
static char **argv = NULL;

void setUp(void)
{

}

void tearDown(void)
{
}


void create_args_tab(void)
{
	argv = (char**)calloc(sizeof(char*), ARGC);
	argv[0] = strdup("pipex");
	argv[1] = strdup("inFile");
	argv[2] = strdup("cat");
	argv[3] = strdup("wc -l");
	argv[4] = strdup("outFile");
}

void free_args_tab(void)
{
	for (int i = ARGC - 1; i >= 0; i--)
		free(argv[i]);
}

void test_parser_only_4_args_should_be_accepted(void)
{
	create_args_tab();
	TEST_ASSERT_NULL(ft_parse_input(4, (char **)argv));
	TEST_ASSERT_NULL(ft_parse_input(3, (char **)argv));
	TEST_ASSERT_NULL(ft_parse_input(2, (char **)argv));
	TEST_ASSERT_NULL(ft_parse_input(1, (char **)argv));
	char *parsed_output = ft_parse_input(ARGC, (char **)argv);
	TEST_ASSERT_NOT_NULL(parsed_output);
	free_args_tab();
}

void test_parser_output_should_result_of_concatenation_of_inputs(void)
{
	create_args_tab();
	char *concatenate_str = (char *)calloc(sizeof(char *), MAX_STR_LEN * ARGC);
	char *parsed_output = NULL;

	for (int i = 1; i < ARGC; i++)
	{
		strcat(concatenate_str, argv[i]);
		if (i < ARGC - 1)
			strcat(concatenate_str, " ");
	}
	parsed_output = ft_parse_input(ARGC, (char **)argv);
	TEST_ASSERT_NOT_NULL(parsed_output);
	TEST_ASSERT_EQUAL_STRING(concatenate_str, parsed_output);
	if(parsed_output)
		free(parsed_output);
	free_args_tab();
}

#endif // TEST
