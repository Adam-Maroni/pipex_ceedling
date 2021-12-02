/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:11:29 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/02 15:22:08 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listpipex.h"

/*
 * This function initliaze the list
 * based on arguments inserted as program's input.
 */
t_list_pipex	*ft_init_pipex_list(char **argv, t_list_pipex *list)
{
	if (!argv)
		return (NULL);
	if (!list)
		list = (t_list_pipex *)ft_calloc(sizeof(t_list_pipex), 1);
	list->file = ft_strdup(argv[1]);
	list->cmd_binary = ft_extract_cmd(argv[2]);
	list->cmd_args = ft_extract_cmd_args(argv[2]);
}

void ft_delone_pipex_list(t_list_pipex *list)
{
	free(list->file);
	free(list->cmd_binary);
	free(list->cmd_args);
	free(list);
}

void ft_free_init_pipex_list(t_list_pipex **list)
{
	t_list_pipex	*current;
	t_list_pipex	*previous;

	previous = (*list)->next;
	while (previous)
	{
		current = previous->next;
		ft_delone_pipex_list(previous);
		previous = current;
	}
	ft_delone_pipex_list(*list);
	(*list) = NULL;
}
