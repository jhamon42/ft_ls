/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:43:25 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/30 18:03:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_tree	*add_leaf(t_file *new_data)
{
	t_tree *new_branch;

	if (!(new_branch = malloc(sizeof(t_tree))))
		exit_custum("malloc", EXIT_ERROR);
	ft_bzero(new_branch, sizeof(t_tree));
	new_data->place = 1;
	new_branch->data = new_data;
	return (new_branch);
}

static void		sort_tree(t_tree *tmp, t_file *new_data, char flags)
{
	int cmp;

	cmp = flags & T ? tmp->data->time - new_data->time
		: ft_strcmp(new_data->name, tmp->data->name);
	cmp = flags & T && cmp == 0 ? ft_strcmp(new_data->name, tmp->data->name)
		: cmp;
	cmp = flags & R ? cmp * -1 : cmp;
	if (cmp > 0)
	{
		if (tmp->right != NULL)
			sort_tree(tmp->right, new_data, flags);
		else
			tmp->right = add_leaf(new_data);
	}
	else
	{
		if (tmp->left != NULL)
			sort_tree(tmp->left, new_data, flags);
		else
			tmp->left = add_leaf(new_data);
	}
}

void			fild_multi_tree(t_tree *tree, char **dir_files, char flags)
{
	int			i;
	t_tree		*tmp;
	t_file		*new_data;

	i = 0;
	while (dir_files[i])
	{
		tmp = tree;
		new_data = create_data_file(dir_files[i]);
		sort_tree(tmp, new_data, flags);
		i++;
	}
}

void			fild_tree(t_tree *tree, DIR *dir_files, char flags, char *path)
{
	struct dirent	*dent;
	t_file			*new_data;

	if ((dent = readdir(dir_files)) != NULL)
		tree->data = create_data_file(ft_strjoin(path, dent->d_name));
	while ((dent = readdir(dir_files)) != NULL)
	{
		new_data = create_data_file(ft_strjoin(path, dent->d_name));
		sort_tree(tree, new_data, flags);
	}
}
