#include "../pipex.h"
#include <stdlib.h>
#include <string.h>

char *preparate_cmd(char **argv)
{
	char *cmd_to_exectute = (char *)calloc(sizeof(char),  100);
	strcat(cmd_to_exectute, argv[2]);
	strcat(cmd_to_exectute, " ");
	strcat(cmd_to_exectute, argv[1]);
	return (cmd_to_exectute);
}

char **test_tabexecve(t_list_pipex *list)
{
	char **rt = (char**)calloc(sizeof(char*), 4);
	rt[0] = strdup(list->next->content);
	rt[1] = strdup(list->next->next->content);
	rt[2] = strdup(list->content);
	rt[3] = NULL;
	return (rt);
}

//pipex file1 cmd1
/* Entourer les arguments en entree avec des guillemets */
int main(int argc, char **argv, char **envp)
{
	if (argc != 3)
		return (-1); //Error
	t_list_pipex *list = ft_init_pipex_list(argc, argv);
	char **tab_execve = test_tabexecve(list);
	char *cmd_to_exectute = preparate_cmd(argv);
	//FILE1
	FILE *f1 = freopen(OUTPUT1,"w+", stdout);	
	system(cmd_to_exectute);
	fclose(f1);
	//FILE2
	FILE *f2 = freopen(OUTPUT2,"w+", stdout);	
	execve(ft_return_cmd_absolute_path(list->next->content, ft_extract_envar_path(envp)), tab_execve, envp);
	fclose(f2);
	//FREE
	free(cmd_to_exectute);
	ft_free_2dtab((void **)tab_execve);
	ft_free_pipex_list(&list);
	return (0);
}





//execve 
// 1: le chemin de la commande
// 2: [0] = cmd , [1] = args, [2]=file , [3]= NULL
// 3: envp
