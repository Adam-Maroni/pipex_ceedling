/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:28:26 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/02 14:26:25 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list_pipex
{
	char *file;
	char *cmd_binary;
	char *cmd_args;
	struct s_list *next;
} t_list_pipex;

/* parser.c */
void *ft_parsing(int argc, char **argv, char **envp);
char *ft_extract_envar_path(char **envp);
char *ft_return_cmd_path(char *path_string, char *cmd);
char *ft_extract_cmd(char *arg);
char *ft_extract_cmd_args(char *arg);
void	ft_init_pipex_list(char **argv, t_list_pipex *list);
void	ft_free_pipex_list(t_list_pipex *list);
#endif
