#ifdef TEST

#include "unity.h"

#include "parser.h"
#include <string.h>

#define ARGC 5
#define MAX_STR_LEN 100
char argv[ARGC][MAX_STR_LEN] = {"pipex", "inFile", "cat", "wc -l", "outFile"};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parser_only_4_args_should_be_accepted(void)
{
    TEST_ASSERT_NULL(ft_parse_input(4, (char **)argv));
    TEST_ASSERT_NULL(ft_parse_input(3, (char **)argv));
    TEST_ASSERT_NULL(ft_parse_input(2, (char **)argv));
    TEST_ASSERT_NULL(ft_parse_input(1, (char **)argv));
    char *parsed_output = ft_parse_input(ARGC, (char **)argv);
    TEST_ASSERT_NOT_NULL(parsed_output);
}

void test_parser_output_should_result_of_concatenation_of_inputs(void)
{
    char *concatenate_str = (char *)calloc(sizeof(char *), MAX_STR_LEN * ARGC);
    char *parsed_output = NULL;

    for (int i = 0; i < ARGC; i++)
    {
        strcat(concatenate_str, argv[i]);
        if (i < ARGC - 1)
            strcat(concatenate_str, " ");
    }
    parsed_output = ft_parse_input(ARGC, (char **)argv);
    TEST_ASSERT_NOT_NULL(parsed_output);
    TEST_ASSERT_EQUAL_STRING(concatenate_str, parsed_output);
    free(concatenate_str);
    free(concatenate_str);
}

#endif // TEST
