/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:29:19 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/10 12:47:44 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execve.h"

void	ft_init_execve_data(t_execve_data *data)
{
	if (!data)
		return ;
	data->cmd_path = NULL;
	data->prog_tab[0] = NULL;
	data->prog_tab[1] = NULL;
	data->prog_tab[2] = NULL;
	data->prog_tab[3] = NULL;
	data->envp = NULL;
}

/* Format data to be fed to execve */
t_execve_data	*ft_return_excve_data(char *cmd, char *cmd_args,
		char *file, char **envp)
{
	t_execve_data	*rt;
	size_t			i;

	if (!cmd || !envp)
		return (NULL);
	rt = (t_execve_data *)calloc(sizeof(*rt), 1);
	if (!rt)
		return (NULL);
	ft_init_execve_data(rt);
	rt->cmd_path = ft_return_cmd_absolute_path(cmd,
			ft_extract_envar_path(envp));
	rt->prog_tab[0] = ft_strdup(cmd);
	i = 1;
	if (cmd_args)
	{
		rt->prog_tab[i] = ft_strdup(cmd_args);
		i++;
	}
	if (file)
	{
		rt->prog_tab[i] = ft_strdup(file);
		i++;
	}
}

/*
 * this function go through the list
 * from the starting point,
 * then return the data to feed inside execve 
 * */
t_execve_data	*ft_list_to_execve(t_list_pipex *start, char **envp)
{
	size_t			i;
	t_list_pipex	*tmp;
	t_execve_data	*rt;

	if (!start || !envp)
		return (NULL);
	tmp = start;
	i = 0;
	rt = NULL;
	while (tmp && ft_strncmp(tmp->content, "|", 1))
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 3)
		rt = ft_return_excve_data(start->content,
				start->next->content, start->next->next->content, envp);
	else if (i == 2 && !access(start->next->content, F_OK))
		rt = ft_return_excve_data(start->content, "",
				start->next->content, envp);
	else if (i == 2)
		rt = ft_return_excve_data(start->content,
				start->next->content, NULL, envp);
	else if (i == 1)
		rt = ft_return_excve_data(start->content, NULL, NULL, envp);
	return (rt);
}

void	ft_free_execve_data(t_execve_data *data)
{
	if (!data)
		return ;
	if (data->cmd_path)
		free(data->cmd_path);
	if (data->prog_tab[0])
		free(data->prog_tab[0]);
	if (data->prog_tab[1])
		free(data->prog_tab[1]);
	if (data->prog_tab[2])
		free(data->prog_tab[2]);
	free(data);
}
