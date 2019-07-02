/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_parms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:35:15 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/02 17:01:24 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_all(t_tree *tree, t_tree *tree_dos)
{
	if (tree->data)
		free_tree(tree);
	if (tree_dos->data)
		free_tree(tree_dos);
}

void	in_dos(t_tree *tree, char flags)
{
	DIR		*dir;
	t_tree	*tree_tmp;
	t_file	*data;

	if ((tree_tmp = ft_memalloc(sizeof(t_tree))) == NULL)
		exit_custum("malloc", -1); //
	data = create_data_file(tree->data->name);
	dir = opendir(data->path);
	if (dir != NULL)
	{
		fild_tree(tree_tmp, dir, flags, data->path);
		closedir(dir);
		L & flags && (tree_tmp->weight > 1)
			? ft_printf("total %lld\n", tree_tmp->tt_blocks) : 0;
		print_arb(tree_tmp, flags);
	}
	if (flags & GR)
		recursive_while(flags, tree_tmp);
}

void	print_dos(t_tree *tree, char flags)
{
	if (tree->left == NULL)
	{
		ft_printf("%s:\n", tree->data->name);
		in_dos(tree, flags);
		ft_printf("\n");
		if (tree->right != NULL)
			print_dos(tree->right, flags);
	}
	else
	{
		print_dos(tree->left, flags);
		ft_printf("%s:\n", tree->data->name);
		in_dos(tree, flags);
		if (tree->right != NULL)
		{
			ft_printf("\n");
			print_dos(tree->right, flags);
		}
	}
}

void	marabou(t_tree *tree, t_file *data, char flags)
{
	if (!tree->data)
		tree->data = data;
	else
		sort_tree(tree, data, flags);
	tree->weight++;
}

void	multi_print(char **files, char flags)
{
	t_tree	*tree;
	t_tree	*tree_dos;
	t_file	*data;
	int		i;

	i = 0;
	(tree = ft_memalloc(sizeof(t_tree))) == NULL
		? exit_custum("malloc", -1) : 0; //
	(tree_dos = ft_memalloc(sizeof(t_tree))) == NULL
		? exit_custum("malloc", -1) : 0; //
	while (files[i])
	{
		if ((data = create_data_file(files[i++])) != NULL)
		{
			if (data->perm_type[0] != 'd')
				marabou(tree, data, flags);
			else
				marabou(tree_dos, data, flags);
		}
	}
	tree->weight > 0 ? print_arb(tree, flags) : 0;
	tree->weight > 0 && tree_dos->weight > 0 ? ft_printf("\n") : 0;
	tree_dos->weight > 0 ? print_dos(tree_dos, flags) : 0;
	free_all(tree, tree_dos);
}
