#ifdef TEST

#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "execve.h"

TEST_FILE("../src/parser.c")
TEST_FILE("../src/extract.c")
TEST_FILE("../src/parser.c")

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

	envp = (char**)calloc(argc , sizeof(char*));
	envp[0] = strdup("envp0");
	envp[1] = strdup("envp1");
	envp[2] = strdup("PATH=/mnt/nfs/homes/amaroni/.brew/bin:/mnt/nfs/homes/amaroni/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[3] = strdup("envp3");
	envp[4] = strdup("envp4");
	envp[5] = strdup("envp5");
	envp[6] = NULL;
}

void tearDown(void)
{
	for (int i = 0; i < argc ; i++)
	{
		free(envp[i]);
		free(argv[i]);
	}
	free(argv);
	free(envp);
}

/* ft_return_excve_data */
void test_ft_return_excve_data_should_return_null_if_null_cmd_or_envp_is_null(void)
{
	char *cmd = CMD1;
	char *cmd_args = CMD1ARGS;
	char *file = FILE1;

	TEST_ASSERT_NULL(ft_return_excve_data(NULL,cmd_args, file, envp));
	TEST_ASSERT_NULL(ft_return_excve_data(cmd,cmd_args, file, NULL));
	TEST_ASSERT_NULL(ft_return_excve_data(NULL,cmd_args, file, NULL));
}
void test_ft_return_excve_data_should_return_data_even_if_file_is_null(void)
{
	char *cmd;
	char *cmd_args;
	char *cmd_absolute_path;
	t_execve_data *data;

	cmd = CMD1;
	cmd_args = CMD1ARGS;
	cmd_absolute_path = ft_return_cmd_absolute_path(cmd, ft_extract_envar_path(envp));
	data = ft_return_excve_data(cmd, cmd_args, NULL, envp);
	TEST_ASSERT_EQUAL_STRING(cmd_absolute_path, data->cmd_path);
	TEST_ASSERT_EQUAL_STRING(CMD1,     data->prog_tab[0]);
	TEST_ASSERT_EQUAL_STRING(CMD1ARGS, data->prog_tab[1]);
	TEST_ASSERT_EQUAL_STRING("",    data->prog_tab[2]);
	TEST_ASSERT_NULL(data->prog_tab[3]);
	ft_free_execve_data(data);	
	free(cmd_absolute_path);
}
void test_ft_return_excve_data_should_return_data_even_if_cmdargs_is_null(void)
{
	char *cmd;
	char *cmd_args;
	char *cmd_absolute_path;
	char *file;
	t_execve_data *data;

	cmd = CMD1;
	cmd_args = NULL;
	file = FILE1;
	cmd_absolute_path = ft_return_cmd_absolute_path(cmd, ft_extract_envar_path(envp));
	data = ft_return_excve_data(cmd, cmd_args, file, envp);
	TEST_ASSERT_EQUAL_STRING(cmd_absolute_path, data->cmd_path);
	TEST_ASSERT_EQUAL_STRING(CMD1,     data->prog_tab[0]);
	TEST_ASSERT_EQUAL_STRING("", data->prog_tab[1]);
	TEST_ASSERT_EQUAL_STRING(FILE1, data->prog_tab[2]);
	TEST_ASSERT_NULL(data->prog_tab[3]);
	ft_free_execve_data(data);	
	free(cmd_absolute_path);
}
void test_ft_return_excve_data(void)
{
	char *cmd;
	char *cmd_args;
	char *file;
	char *cmd_absolute_path;
	t_execve_data *data;

	cmd = CMD1;
	cmd_args = CMD1ARGS;
	file = FILE1;
	cmd_absolute_path = ft_return_cmd_absolute_path(cmd, ft_extract_envar_path(envp));
	data = ft_return_excve_data(cmd, cmd_args, file, envp);
	TEST_ASSERT_EQUAL_STRING(cmd_absolute_path, data->cmd_path);
	TEST_ASSERT_EQUAL_STRING(data->prog_tab[0], CMD1);
	TEST_ASSERT_EQUAL_STRING(data->prog_tab[1], CMD1ARGS);
	TEST_ASSERT_EQUAL_STRING(data->prog_tab[2], FILE1);
	TEST_ASSERT_NULL(data->prog_tab[3]);
	ft_free_execve_data(data);	
	free(cmd_absolute_path);
}

#endif // TEST








