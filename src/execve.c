/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:29:19 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/09 14:32:15 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execve.h"

/* Format data to be fed to execve */
t_execve_data	*ft_return_excve_data(char *cmd, char *cmd_args,
	char *file, char **envp)
{
	t_execve_data	*rt;

	if (!cmd || !envp)
		return (NULL);
	rt = (t_execve_data *)calloc(sizeof(*rt), 1);
	if (!rt)
		return (NULL);
	ft_init_execve_data(rt);
	rt->cmd_path = ft_return_cmd_absolute_path(cmd,
			ft_extract_envar_path(envp));
	rt->prog_tab[0] = ft_strdup(cmd);
	if (!cmd_args)
		rt->prog_tab[1] = ft_strdup("");
	else
		rt->prog_tab[1] = ft_strdup(cmd_args);
	if (!file)
		rt->prog_tab[2] = ft_strdup("");
	else
		rt->prog_tab[2] = ft_strdup(file);
	rt->prog_tab[3] = NULL;
	rt->envp = envp;
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

void	ft_init_execve_data(t_execve_data *data)
{
	if (!data)
		return ;
	data->cmd_path = NULL;
	data->prog_tab[0] = NULL;
	data->prog_tab[1] = NULL;
	data->prog_tab[2] = NULL;
}
