/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:18:24 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/13 15:15:12 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_while(char flags, int iterate, char **dir_files)
{
	t_tree *tree;

	if (!(tree = malloc(sizeof(t_tree))))
		exit_custum("malloc", EXIT_ERROR);
	ft_bzero(tree, sizeof(t_tree));
	fild_tree(tree, dir_files, flags);
}
