/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:28:26 by amaroni           #+#    #+#             */
/*   Updated: 2021/11/26 18:59:02 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

/* parser.c */
char	*ft_strjoin_plus_spaces(int tabsize, char **tab);
char	*ft_parse_input(int argc, char **argv);
#endif
