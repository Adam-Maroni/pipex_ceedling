#ifdef TEST

#include "unity.h"

#include "parser.h"

int argc = 5;
char **argv= {"pipex", "inFile", "cat", "wc -l", "OutFile"};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parser_only_4_args_should_be_accepted(void)
{
    //char **argv= {"pipex", "inFile", "cat", "wc -l", "OutFile"};
    TEST_ASSERT_NULL(ft_parse_input(4, argv));
    TEST_ASSERT_NULL(ft_parse_input(3, argv));
    TEST_ASSERT_NULL(ft_parse_input(2, argv));
    TEST_ASSERT_NULL(ft_parse_input(1, argv));
    char *parsed_output = ft_parse_input(argc, argv);
    TEST_ASSERT_NOT_NULL(parsed_output);

}


#endif // TEST
