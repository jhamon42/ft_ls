/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:18:24 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/04 16:58:01 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	recursive_while(char flags, char **dir_files)
{
	t_tree *tree;

	if (!(tree = malloc(sizeof(t_tree))))
		exit_custum("malloc", EXIT_ERROR);
	ft_printf("\n");
	ft_bzero(tree, sizeof(t_tree));
	printf(" -> %s\n", dir_files[0]);
	tree->data = create_data_file(dir_files[0]);
	fild_tree(tree, dir_files + 1, flags);
	print_arb(tree, flags);
	if (flags & GR)
	{
	}
}
