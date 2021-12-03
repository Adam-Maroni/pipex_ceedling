/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:11:29 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/03 15:07:15 by amaroni          ###   ########.fr       */
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
	if (list)
	{
		printf("list deja initialisée\n");
		return (NULL);
	}
	list = ft_new_pipex_list(argv[1], ft_extract_cmd(argv[2]), ft_extract_cmd_args(argv[2]));
	ft_addback_pipex_list(&list, ft_new_pipex_list(argv[4], ft_extract_cmd(argv[3]), ft_extract_cmd_args(argv[3])));
	return (list);
}

void ft_delone_pipex_list(t_list_pipex *list)
{
	free(list->file);
	free(list->cmd_binary);
	free(list->cmd_args);
	free(list);
}

void ft_free_pipex_list(t_list_pipex **list)
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

void ft_addback_pipex_list(t_list_pipex **alist, t_list_pipex *new)
{
	t_list_pipex *list;

	list = ft_last_pipex_list(*alist);
	if (!list)
		*alist = new;
	else
		list->next = new;
	new->next = NULL;
}

t_list_pipex *ft_last_pipex_list(t_list_pipex *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}


t_list_pipex *ft_new_pipex_list(char *file, char *cmd_binary, char *cmd_args)
{
	t_list_pipex	*new;

	new = (t_list_pipex *)malloc(sizeof(t_list_pipex));
	if (!new)
		return (NULL);
	new->file = ft_strdup(file);
	new->cmd_binary = ft_strdup(cmd_binary);
	new->cmd_args = ft_strdup(cmd_args);
	new->next = NULL;
	return (new);

}
