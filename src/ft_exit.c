/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:54:45 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/02 16:52:13 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_tree(t_tree *tree)
{
	if (tree->left == NULL)
	{
		if (tree->right != NULL)
			free_tree(tree->right);


	}
	else
	{
		free_tree(tree->left);
		if (tree->right != NULL)
			free_tree(tree->right);
	}
	ft_bzero(tree->data, sizeof(t_file));
	ft_memdel((void*)&tree->data);
	ft_bzero(tree, sizeof(t_tree));
	ft_memdel((void*)&tree);
}

void	exit_custum(char *error, int type)
{
	perror(error);
	// oblie pas de tous free
	exit(type);
}
