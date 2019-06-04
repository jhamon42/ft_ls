/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:50:40 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/04 16:24:15 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <grp.h>
#include <sys/types.h>
#define SYS_ERR -1

int		ft_reverce(DIR *dir)
{
	struct dirent *dent;

	if ((dent = readdir(dir)) != NULL)
	{
		ft_reverce(dir);
		printf("%s\n", dent->d_name);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	DIR		*dir;

	if (argc != 2)
	{
		argv[1] = ".";
	}
	dir = opendir(argv[1]);
	if (dir != NULL)
	{
		ft_reverce(dir);
		closedir(dir);
	}
	exit(EXIT_SUCCESS);
}
