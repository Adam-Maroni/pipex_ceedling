/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:53:56 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/03 16:23:08 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * Prend entree la commande et la string obtenue grâce à l'extraction de path
 * puis supprime "PATH=" de cette string, split et concatene chaque chemin avec la commande
 * pour en déterminer le chemin absolue et termine par vérifier si le chemin est correcte grâce à access()
 */
char *ft_return_cmd_binary_absolute_path(char *cmd_binary, char *path_str)
{
	char **absolute_path;
	char *nopath_str;
	size_t i;
	size_t len;
	char *validated_path;

	if (!cmd_binary && !path_str)
		return (NULL);
	validated_path = NULL;
	nopath_str[0] = path_str[5];
	absolute_path = ft_split(nopath_str, ':');
	i = 0;
	while (absolute_path[i])
	{
		len = ft_strlen(absolute_path[i]) + ft_strlen(cmd_binary) + 2; // '\' + '\0'
		free(absolute_path[i]);
		absolute_path[i] = ft_calloc(sizeof(char), len);
		ft_strlcat(absolute_path[i], "\\", ft_strlen(absolute_path[i]) + 2);
		ft_strlcat(absolute_path[i], cmd_binary, ft_strlen(absolute_path[i]) + ft_strlen(cmd_binary) + 1);
		if (!access((const char *)absolute_path[i], F_OK))
			validated_path = ft_strdup(absolute_path[i]);
		i++;
	}
	i = 0;
	while (absolute_path[i])
	{
		free(absolute_path[i]);
		i++;
	}
	free (absolute_path);
	return (validated_path);
}

void	*ft_parsing(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (NULL);
	//Save info to pipex list
	//ft_rt_envar_path
	return (argv[1]);
}

