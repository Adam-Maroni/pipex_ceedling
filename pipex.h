/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:28:26 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/03 18:00:09 by amaroni          ###   ########.fr       */
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
	struct s_list_pipex *next;
} t_list_pipex;

/* parser.c */
void *ft_parsing(int argc, char **argv, char **envp);
char *ft_return_cmd_binary_absolute_path(char *cmd_binary, char *path_str);

/* extract.c */
char *ft_extract_envar_path(char **envp);
char *ft_extract_cmd(char *arg);
char *ft_extract_cmd_args(char *arg);

t_list_pipex	*ft_init_pipex_list(char **argv, t_list_pipex *list);
void ft_delone_pipex_list(t_list_pipex *list);
void ft_free_pipex_list(t_list_pipex **list);
void ft_addback_pipex_list(t_list_pipex **alst, t_list_pipex *new);
t_list_pipex *ft_new_pipex_list(char *file, char *cmd_binary, char *cmd_args);
t_list_pipex *ft_last_pipex_list(t_list_pipex *list);
#endif
