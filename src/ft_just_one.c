/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:35:48 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/02 17:02:27 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	simple_print(char *files, char flags)
{
	DIR		*dir;
	t_tree	*tree;
	t_file	*data;

	data = create_data_file(files);
	if (data->perm_type[0] != 'd')
	{
		flags & L ? print_l_mode(data)
			: ft_printf("%s\n", data->name);
		ft_bzero(data, sizeof(t_file));
		ft_memdel((void*)&data);
	}
	else
	{
		if ((tree = ft_memalloc(sizeof(t_tree))) == NULL)
			exit_custum("malloc", -1);
		dir = opendir(data->path);
		if (dir != NULL)
		{
			fild_tree(tree, dir, flags, data->path);
			closedir(dir);
			L & flags && (tree->weight > 1)
				? ft_printf("total %lld\n", tree->tt_blocks) : 0;
			print_arb(tree, flags);
		}
		if (flags & GR)
			recursive_while(flags, tree);
		free_tree(tree);
	}
}
