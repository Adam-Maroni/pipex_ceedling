/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:11:29 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/02 14:50:07 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

/*
 * This function initliaze the list
 * based on arguments inserted as program's input.
 */
void	ft_init_pipex_list(char **argv, t_list_pipex *list)
{
	list->file = ft_strdup(argv[1]);
	list->cmd_binary = ft_extract_cmd(argv[2]);
	list->cmd_args = ft_extract_cmd_args(argv[2]);

	//Todel
	free(list->file);
	free(list->cmd_binary);
	free(list->cmd_args);
}
