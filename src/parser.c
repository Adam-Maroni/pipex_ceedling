/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:26:40 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/26 19:08:22 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * Change i to decide where to start in the tab.
 * i = -1 start at tab[0]
 * i = 0 start at tab[1]
 */
char	*ft_strjoin_plus_spaces(int tabsize, char **tab)
{
	size_t	i;
	size_t	strlentotal;
	char	*concatenate_args;

	strlentotal = 0;
	i = 0;
	while (++i < tabsize)
		strlentotal += ft_strlen(tab[i]) + 1;
	concatenate_args = (char *)ft_calloc(sizeof(char), strlentotal);
	if (!concatenate_args)
		return (NULL);
	i = 0;
	while (++i < tabsize)
	{
		ft_strlcat(concatenate_args, tab[i],
			ft_strlen(concatenate_args) + ft_strlen(tab[i]) + 1);
		if (i < tabsize - 1)
			ft_strlcat(concatenate_args, " ", ft_strlen(concatenate_args) + 2);
	}
	return (concatenate_args);
}

/*
 * argc = nb of string in argv tab
 * if argc is not 5 then return NULL to indicate an error.
 * Otherwise concatenate the input (and spaced the element)
 * and return that new concatenated string
 */
char	*ft_parse_input(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("Not the right number of arguments\n");
		return (NULL);
	}
	return (ft_strjoin_plus_spaces(argc, argv));
}
