/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fild_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:43:25 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/13 16:41:44 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	static	*create_data_file(char *dir_file)
{
	t_file			*data;
	struct stat		sb;
	struct passwd	*pwd;
	struct group	*grp;
	int				i;

	i = 0;
	if (!(data = malloc(sizeof(t_file))))
		exit_custum("malloc", EXIT_ERROR);
	ft_bzero(data, sizeof(t_file));
	if (lstat(dir_file, &sb) == -1)
		exit_custum("stat", EXIT_ERROR);
	if ((pwd = getpwuid(sb.st_uid)) == NULL)
		exit_custum("passwd", EXIT_ERROR);
	if ((grp = getgrgid(sb.st_gid)) == NULL)
		exit_custum("group", EXIT_ERROR);
	if (S_ISLNK(sb.st_mode)
		&& (i = readlink(dir_file, data->link_name, BUFSIZ)) == -1)
		exit_custum("readlink", EXIT_ERROR);
	cp_data(&sb, pwd, grp, data);
	data->link_name[i] = '\0';
	data->name = dir_file;
	print_l_mode(data);
	return (data);
}

static t_tree	*add_leaf(t_file *new_data)
{
	t_tree *new_branch;

	if (!(new_branch = malloc(sizeof(t_tree))))
		exit_custum("malloc", EXIT_ERROR);
	ft_bzero(new_branch, sizeof(t_tree));
	new_branch->data = new_data;
	return (new_branch);
}

static void		sort_name(t_tree *tmp, t_file *new_data)
{
	if (ft_strcmp(tmp->data->name, new_data->name) > 0)
	{
		if (tmp->right != NULL)
			tmp = tmp->right;
		else
			tmp->right = add_leaf(new_data);
	}
	else
	{
		if (tmp->left != NULL)
			tmp = tmp->left;
		else
			tmp->left = add_leaf(new_data);
	}
}

static void		sort_time(t_tree *tmp, t_file *new_data)
{
	if (tmp->data->time > new_data->time)
	{
		if (tmp->right != NULL)
			tmp = tmp->right;
		else
			tmp->right = add_leaf(new_data);
	}
	else
	{
		if (tmp->left != NULL)
			tmp = tmp->left;
		else
			tmp->left = add_leaf(new_data);
	}
}

void			fild_tree(t_tree *tree, char **dir_files, char flags)
{
	int			i;
	t_tree		*tmp;
	t_file		*new_data;

	i = 0;
	while (dir_files[i])
	{
		tmp = tree;
		new_data = create_data_file(dir_files[i]);
		while (tmp->data != NULL)
		{
			if (flags & T)
				sort_time(tmp, new_data);
			else
				sort_name(tmp, new_data);
		}
		i++;
	}
}
