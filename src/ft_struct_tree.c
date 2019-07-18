/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:43:25 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/16 19:40:55 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	t_tree	*add_leaf(t_file *new_data, t_freemoi *eldoctor)
{
	t_tree *new_branch;

	if (!(new_branch = ft_memalloc(sizeof(t_tree))))
		exit_custum("malloc", EXIT_ERROR, eldoctor);
	new_branch->data = new_data;
	return (new_branch);
}

void			sort_tree(
t_tree *tmp,
t_file *new_data,
char flags,
t_freemoi *eldoctor)
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
			sort_tree(tmp->right, new_data, flags, eldoctor);
		else
			tmp->right = add_leaf(new_data, eldoctor);
	}
	else
	{
		if (tmp->left != NULL)
			sort_tree(tmp->left, new_data, flags, eldoctor);
		else
			tmp->left = add_leaf(new_data, eldoctor);
	}
}

void			fild_multi_tree(
t_tree *tree,
char **dir_files,
char flags,
t_freemoi *eldoctor
)
{
	int			i;
	t_tree		*tmp;
	t_file		*new_data;

	i = 0;
	while (dir_files[i])
	{
		tmp = tree;
		new_data = create_data_file(dir_files[i], eldoctor);
		sort_tree(tmp, new_data, flags, eldoctor);
		i++;
	}
}

void			fild_tree(
	DIR *dir_files,
	char *path,
	t_apaletemps *plt,
	t_freemoi *eldoctor)
{
	struct dirent	*dent;
	t_file			*new_data;
	char			*tmp;

	if ((dent = readdir(dir_files)) != NULL)
	{
		tmp = ft_strjoin(path, dent->d_name);
		plt->tree->data = create_data_file(tmp, eldoctor);
		ft_strdel(&tmp);
	}
	plt->tree->tt_blocks = plt->tree->data->block_alloc;
	while ((dent = readdir(dir_files)) != NULL)
	{
		tmp = ft_strjoin(path, dent->d_name);
		new_data = create_data_file(tmp, eldoctor);
		ft_strdel(&tmp);
		plt->tree->tt_blocks += new_data->block_alloc;
		plt->tree->weight++;
		sort_tree(plt->tree, new_data, plt->flags, eldoctor);
	}
}
