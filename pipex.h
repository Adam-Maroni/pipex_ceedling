/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:28:26 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/04 21:30:36 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_list_pipex
{
	char	*content;
	struct s_list_pipex *next;
} t_list_pipex;

/* parser.c */
void	ft_free_2dtab(void **tab);
char	*ft_strcat_path_and_cmd(char *path, char *cmd);
char	*ft_return_cmd_absolute_path(char *cmd, char *path);
void	*ft_parsing(int argc, char **argv, char **envp);
void	ft_swap2elements(char **tab, size_t index1, size_t index2);
char	**ft_argv_to_excveargv(int argc, char **argv);

/* extract.c */
char	*ft_extract_envar_path(char **envp);
char 	*ft_extract_cmd(char *arg);
char 	*ft_extract_cmd_args(char *arg);

/* listpipex */
t_list_pipex	*ft_init_pipex_list(int argc, char **argv);
void	ft_delone_pipex_list(t_list_pipex *list);
void	ft_free_pipex_list(t_list_pipex **list);
void	ft_addback_pipex_list(t_list_pipex **alist, t_list_pipex *new);
t_list_pipex	*ft_last_pipex_list(t_list_pipex *list);
t_list_pipex	*ft_new_pipex_list(char *content);
#endif





















