/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_parms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:35:15 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/18 16:52:45 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_dos(t_tree *tree, char flags, t_freemoi *eldoctor)
{
	if (tree->left == NULL)
	{
		ft_printf("%s:\n", tree->data->name);
		in_dos(tree, flags, eldoctor);
		if (tree->right != NULL)
		{
			ft_printf("\n");
			print_dos(tree->right, flags, eldoctor);
		}
	}
	else
	{
		print_dos(tree->left, flags, eldoctor);
		ft_printf("%s:\n", tree->data->name);
		in_dos(tree, flags, eldoctor);
		if (tree->right != NULL)
		{
			ft_printf("\n");
			print_dos(tree->right, flags, eldoctor);
		}
	}
}

void	free_all(t_tree *tree,
	t_tree *tree_dos,
	char flags,
	t_freemoi *eldoctor)
{
	tree->weight > 0 ? print_arb(tree, flags) : 0;
	tree->weight > 0 && tree_dos->weight > 0 ? ft_printf("\n") : 0;
	tree_dos->weight > 0 ? print_dos(tree_dos, flags, eldoctor) : 0;
	free_patient(&eldoctor);
	free_patient(&eldoctor);
}

void	marabou(t_tree *tree, t_file *data, char flags, t_freemoi *eldoctor)
{
	if (!tree->data)
		tree->data = data;
	else
		sort_tree(tree, data, flags, eldoctor);
	tree->weight++;
}

void	multi_print(char **files, char flags, t_freemoi *eldoctor)
{
	t_tree	*tree;
	t_tree	*tree_dos;
	t_file	*data;
	int		i;

	i = 0;
	if (!(tree = ft_memalloc(sizeof(t_tree))))
		exit_custum("malloc", -1, eldoctor);
	add_patient(&eldoctor, (void*)&tree, 2);
	if (!(tree_dos = ft_memalloc(sizeof(t_tree))))
		exit_custum("malloc", -1, eldoctor);
	add_patient(&eldoctor, (void*)&tree_dos, 2);
	while (files[i])
	{
		if ((data = create_data_file(files[i++], eldoctor)) != NULL)
		{
			if (data->perm_type[0] != 'd')
				marabou(tree, data, flags, eldoctor);
			else
				marabou(tree_dos, data, flags, eldoctor);
		}
	}
	free_all(tree, tree_dos, flags, eldoctor);
}
