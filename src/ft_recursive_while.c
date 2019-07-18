/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:18:24 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/18 16:36:39 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		is_dir(char flags, t_file *data, t_freemoi *eldoctor)
{
	DIR		*dir;

	if ((dir = opendir(data->path)))
	{
		closedir(dir);
		ft_printf("\n%.*s:\n", ft_strlen(data->path) - 1, data->path);
		simple_print(data->path, flags, eldoctor);
	}
	else if (errno == EACCES && data->perm_type[0] == 'd')
	{
		ft_printf("\n%s:\n", data->path);
		write(2, "./ft_ls: ", 9);
		perror(data->name);
	}
}

void			recursive_while(char flags, t_tree *tree, t_freemoi *eldoctor)
{
	if (tree->left == NULL)
	{
		if (!ft_strequ(tree->data->name, ".")
			&& !ft_strequ(tree->data->name, "..")
			&& (tree->data->name[0] != '.' || A & flags))
			is_dir(flags, tree->data, eldoctor);
		if (tree->right != NULL)
			recursive_while(flags, tree->right, eldoctor);
	}
	else
	{
		recursive_while(flags, tree->left, eldoctor);
		if (!ft_strequ(tree->data->name, ".")
			&& !ft_strequ(tree->data->name, "..")
			&& (tree->data->name[0] != '.' || A & flags))
			is_dir(flags, tree->data, eldoctor);
		if (tree->right != NULL)
			recursive_while(flags, tree->right, eldoctor);
	}
}
