/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:35:48 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/30 17:57:43 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// int		ft_reverce(DIR *dir)
// {
// 	struct dirent *dent;

// 	if ((dent = readdir(dir)) != NULL)
// 	{
// 		ft_reverce(dir);
// 		ft_printf("%s\n", dent->d_name);
// 	}
// 	return (1);
// }

void	simple_print(char **files, char flags)
{
	DIR		*dir;
	t_tree	*tree;
	t_file	*data;

	data = create_data_file(files[0]);
	if (data->perm_type[0] != 'd')
		flags & L ? print_l_mode(data)
			: ft_printf("%s\n", data->name);
	else
	{
		if ((tree = malloc(sizeof(t_tree))) == NULL)
			exit_custum("malloc", -1);
		ft_bzero(tree, sizeof(t_tree));
		dir = opendir(data->path);
		printf("%s\n", data->name);
		if (dir != NULL)
		{
			fild_tree(tree, dir, flags, data->path);
			closedir(dir);
			print_arb(tree, flags);
		}
	}
}
