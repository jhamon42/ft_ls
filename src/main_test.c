/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:50:40 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/14 16:04:30 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <sys/types.h>
#define SYS_ERR -1

int		ft_reverce(DIR *dir)
{
	struct dirent *dent;

	if ((dent = readdir(dir)) != NULL)
	{
		printf("%s\n", dent->d_name);
		ft_reverce(dir);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	DIR		*dir;
	char	buffer[50];

	if (argc != 2)
	{
		argv[1] = ".";
	}
	strcpy(buffer, argv[1]);
	dir = opendir(buffer);
	if (dir != NULL)
	{
		ft_reverce(dir);
		closedir(dir);
	}
	exit(EXIT_SUCCESS);
}
