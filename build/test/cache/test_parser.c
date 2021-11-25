#include "src/parser.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








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



    do {if ((((ft_parse_input(4, argv))) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(21))));}} while(0);

    do {if ((((ft_parse_input(3, argv))) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(22))));}} while(0);

    do {if ((((ft_parse_input(2, argv))) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(23))));}} while(0);

    do {if ((((ft_parse_input(1, argv))) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(24))));}} while(0);

    char *parsed_output = ft_parse_input(argc, argv);

    do {if ((((parsed_output)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(26))));}} while(0);



}
