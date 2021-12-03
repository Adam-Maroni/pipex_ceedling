/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:53:56 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/03 18:56:39 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * Prend entree la commande et la string PATH,
 * supprime "PATH=" de cette string,
 * split la chaine obtenue,
 * concatene chaque chemin avec la commande
 * et determine le chemin absolue.
 */


void	ft_free_2dtab(void **tab)
{
	size_t	i;

	if (!tab)
		return ;
	if (!*tab)
		free(tab);
	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
}

char	*ft_return_cmd_binary_absolute_path(char *cmd_binary, char *path_str)
{
	char	**absolute_path;
	char	*pathless;
	size_t	i;
	size_t	len;
	char	*rt;

	if (!cmd_binary || !path_str)
		return (NULL);
	rt = NULL;
	pathless = ft_substr(path_str, 5, ft_strlen(path_str) - 5 + 1);
	absolute_path = ft_split(pathless, ':');
	free(pathless);
	i = 0;
	while (absolute_path[i])
	{
		//ft_strcat_path_and_cmd
		len = ft_strlen(absolute_path[i]) + ft_strlen(cmd_binary) + 2;
		rt = (char *)calloc(sizeof(char), len);
		ft_strlcpy(rt, absolute_path[i], ft_strlen(absolute_path[i]) + 1);
		ft_strlcat(rt, "/", ft_strlen(rt) + 2);
		ft_strlcat(rt, cmd_binary, ft_strlen(rt) + ft_strlen(cmd_binary) + 1);
		if (access(rt , F_OK) == 0)
			break ;
		if (rt)
			free(rt);
		i++;
	}
	ft_free_2dtab((void **)absolute_path);
	return (rt);
}

/*
 * Return needle if needle found in haystack.
 * If needle not found or haystack is empty
 * return NULL
 */

void	*ft_parsing(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (NULL);
	//Save info to pipex list
	//ft_rt_envar_path
	return (argv[1]);
}

