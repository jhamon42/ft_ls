/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:18:24 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/01 12:51:10 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		is_dir(char flags, char *path_dir)
{
	DIR		*dir;

	dir = opendir(path_dir);
	if (dir)
	{
		closedir(dir);
		ft_printf("\n%.*s:\n", ft_strlen(path_dir) - 1, path_dir);
		simple_print(path_dir, flags);
	}
}

void			recursive_while(char flags, t_tree *tree)
{
	if (tree->left == NULL)
	{
		if (!ft_strequ(tree->data->name, ".")
			&& !ft_strequ(tree->data->name, "..")
			&& (tree->data->name[0] != '.' || A & flags))
			is_dir(flags, tree->data->path);
		if (tree->right != NULL)
			recursive_while(flags, tree->right);
	}
	else
	{
		recursive_while(flags, tree->left);
		if (!ft_strequ(tree->data->name, ".")
			&& !ft_strequ(tree->data->name, "..")
			&& (tree->data->name[0] != '.' || A & flags))
			is_dir(flags, tree->data->path);
		if (tree->right != NULL)
			recursive_while(flags, tree->right);
	}
}
