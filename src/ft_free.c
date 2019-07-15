/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:14:50 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/15 23:05:52 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_tree(t_tree *tree)
{
	// if (tree)
	// {
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
	// }
}

void	free_parms(char **parms)
{
	int i;

	i = 0;
	while (parms[i])
	{
		ft_strdel((void*)&parms[i]);
		i++;
	}
	ft_memdel((void*)&parms);
}

void	free_data(t_file *data)
{
	ft_strdel((void*)&data->user_name);
	ft_strdel((void*)&data->path);
	ft_bzero(data, sizeof(t_file));
	ft_memdel((void*)&data);
}

t_freemoi	*free_patient(t_freemoi *eldoctor)
{
	t_freemoi	*curse;

	curse = eldoctor;
	eldoctor = curse->next;
	curse->pathology == 3 ? free_data(curse->patient) : 0;
	curse->pathology == 2 ? free_tree((t_tree*)curse->patient) : 0;
	curse->pathology == 1 ? free_parms(curse->patient) : 0;
	ft_bzero(curse, sizeof(t_freemoi));
	ft_memdel((void*)&curse);
	return (eldoctor);
}
