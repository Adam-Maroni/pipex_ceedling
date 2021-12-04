#include "../pipex.h"
#include <stdlib.h>
#include <string.h>

char *preparate_cmd(char **argv)
{
	char *cmd_to_exectute = (char *)calloc(sizeof(char),  100);
	strcat(cmd_to_exectute, argv[1]);
	strcat(cmd_to_exectute, " ");
	strcat(cmd_to_exectute, argv[2]);
	return (cmd_to_exectute);
}

//pipex file1 cmd1
/* Entourer les arguments en entree avec des guillemets */
int main(int argc, char **argv, char **envp)
{
	if (argc != 3)
		return (-1); //Error
	ft_swap2elements(argv, 1, 2);
	char **tab_execve = ft_argv_to_excveargv(argc, argv);
	char *cmd_to_exectute = preparate_cmd(argv);
	FILE *f1 = freopen(OUTPUT1,"w+", stdout);	
	system(cmd_to_exectute);
	fclose(f1);
	FILE *f2 = freopen(OUTPUT2,"w+", stdout);	
	execve(ft_return_cmd_absolute_path(argv[1], ft_extract_envar_path(envp)), tab_execve, envp);
	fclose(f2);
	free(cmd_to_exectute);
	ft_free_2dtab((void **)tab_execve);
	return (0);
}






