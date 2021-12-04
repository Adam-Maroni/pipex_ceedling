/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:16:01 by amaroni           #+#    #+#             */
/*   Updated: 2021/12/04 14:59:41 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char *tab[4];
	tab[0] = "./pipex";
	tab[2] = "inFile";
	tab[1] = "cat -A";
	tab[3] = NULL;
	execve("/bin/cat", tab, envp);
	return (0);
}
