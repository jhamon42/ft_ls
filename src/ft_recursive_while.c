/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:18:24 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/04 14:34:37 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		is_dir(char flags, char *path_dir, t_freemoi *eldoctor)
{
	DIR		*dir;

	dir = opendir(path_dir);
	if (dir)
	{
		closedir(dir);
		ft_printf("\n%.*s:\n", ft_strlen(path_dir) - 1, path_dir);
		simple_print(path_dir, flags, eldoctor);
	}
}

void			recursive_while(char flags, t_tree *tree, t_freemoi *eldoctor)
{
	if (tree->left == NULL)
	{
		if (!ft_strequ(tree->data->name, ".")
			&& !ft_strequ(tree->data->name, "..")
			&& (tree->data->name[0] != '.' || A & flags))
			is_dir(flags, tree->data->path, eldoctor);
		if (tree->right != NULL)
			recursive_while(flags, tree->right, eldoctor);
	}
	else
	{
		recursive_while(flags, tree->left, eldoctor);
		if (!ft_strequ(tree->data->name, ".")
			&& !ft_strequ(tree->data->name, "..")
			&& (tree->data->name[0] != '.' || A & flags))
			is_dir(flags, tree->data->path, eldoctor);
		if (tree->right != NULL)
			recursive_while(flags, tree->right, eldoctor);
	}
}
