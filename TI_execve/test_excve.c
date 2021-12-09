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

//delete zhen ft_return_excve_data works
char **test_tabexecve(t_list_pipex *list)
{
	char **rt = (char**)calloc(sizeof(char*), 4);
	rt[0] = strdup(list->next->content);
	rt[1] = strdup(list->next->next->content);
	rt[2] = strdup(list->content);
	rt[3] = NULL;
	return (rt);
}

void ft_free_execve_data(t_execve_data *tofree)
{
	if (tofree->cmd_path)
		free(tofree->cmd_path);
	if (tofree->prog_tab[0])
		free(tofree->prog_tab[0]);
	if (tofree->prog_tab[1])
		free(tofree->prog_tab[1]);
	if (tofree->prog_tab[2])
		free(tofree->prog_tab[2]);
}

/* this function go through the list from the starting point and then return the data to feed inside execve */
t_execve_data *ft_list_to_execve(t_execve_data *t_list_pipex *start, char **envp)
{
	t_list_pipex *tmp;
	size_t i;
	t_execve_data *rt;

	if (!start)
		return (NULL);
	tmp = start;
	i = 0;
	while (tmp || ft_strncmp(tmp->content, "|", sizeof(char)))
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 3)
		rt = ft_return_excve_data(start->content,
				start->next->content, start->next->next->content, envp);
	else if (i == 2 && start->next->conent is a file)
		ft_return_excve_data(start->content, "", start->next->content, envp);
	else if (i == 2 && start->next->content is not a file)
		ft_return_excve_data(start->content,start->next->content,NULL, envp);
	else if (i == 1)
		ft_return_excve_data(start->content, NULL, NULL, envp);
	else
		rt = NULL; //probleme
	return (rt);
}

//pipex file1 cmd1
/* Entourer les arguments en entree avec des guillemets */
int main(int argc, char **argv, char **envp)
{
	if (argc != 3)
		return (-1); //Error
	t_list_pipex *list = ft_init_pipex_list(argc, argv);
	char **tab_execve = ft_return_excve_data(list->content, lis
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
