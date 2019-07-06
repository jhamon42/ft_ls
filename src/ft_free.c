/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:14:50 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/06 14:03:32 by jhamon           ###   ########.fr       */
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
	free_data(tree->data);
	ft_bzero(tree, sizeof(t_tree));
	ft_memdel((void*)&tree);
}

void	free_parms(char **parms)
{
	int i;

	i = 0;
	while (parms[i])
		ft_strdel((void*)&parms[i]);
	parms = NULL;
}

void	free_data(t_file *data)
{
	ft_strdel((void*)&data->name);
	ft_strdel((void*)&data->user_name);
	ft_strdel((void*)&data->group_name);
	ft_strdel((void*)&data->path);
	ft_bzero(data, sizeof(t_file));
	ft_memdel((void*)&data);

}
