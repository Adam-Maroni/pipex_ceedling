/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:26:40 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/26 18:38:00 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* argc = nb of string in argv tab
 * if argc is not 5 then return NULL to indicate an error.
 * Otherwise concatenate the input (and spaced the element)
 * and return that new concatenated string
 */
char	*ft_parse_input(int argc, char **argv)
{
	size_t	i;
	size_t	total_strlen_of_args;
	char	*concatenate_args;

	if (argc != 5)
	{
		printf("Not the right number of arguments\n");
		return (NULL);
	}
	total_strlen_of_args = 0;
	i = 0;
	while (++i < argc)
		total_strlen_of_args += ft_strlen(argv[i]) + 1;
	concatenate_args = (char *)ft_calloc(sizeof(char), total_strlen_of_args);
	i = 0;
	while (++i < argc)
	{
		ft_strlcat(concatenate_args, argv[i],
			ft_strlen(concatenate_args) + ft_strlen(argv[i]) + 1);
		if (i < argc - 1)
			ft_strlcat(concatenate_args, " ", ft_strlen(concatenate_args) + 2);
	}
	return (concatenate_args);
}
