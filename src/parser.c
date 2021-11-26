#include "parser.h"



char    *ft_parse_input(int argc, char **argv)
{
    size_t  i;
    size_t  total_strlen_of_args;
    char *concat_str;

    if (argc != 5)
    {
        printf("Not the right number of arguments\n");
        return (NULL);
    }
    i = 0;
    total_strlen_of_args = 0;
    while (++i < argc)
    {
        printf("ARGV[%d] = %s\n", i, argv[i]);
        total_strlen_of_args += ft_strlen(argv[i]) + 1;
    }
        /*
    concat_str = (char*)ft_calloc(sizeof(char), total_strlen_of_args);
    i = 0;
    while (++i < argc)
        ft_strlcat(concat_str, argv[i], ft_strlen(concat_str) + ft_strlen(argv[i]) + 1);
    return (concat_str);
    */
   printf("TOTAL_STRLEN_OF_ARGS = %d\n", total_strlen_of_args);
    return ("Something");
}
