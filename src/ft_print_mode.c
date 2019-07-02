/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:44:08 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/01 16:58:26 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_l_mode(t_file *data)
{
	ft_printf("%s ", data->perm_type);
	ft_printf("%5d ", data->link_number);
	ft_printf("%s  ", data->user_name);
	ft_printf("%s  ", data->group_name);
	if (data->perm_type[0] == 'b' || data->perm_type[0] == 'c')
	{
		ft_printf("%5ld, ", data->major);
		ft_printf("%5ld ", data->minor);
	}
	else
		ft_printf("%5ld ", data->file_size);
	ft_printf("%s ", data->last_modif);
	ft_printf("%s", data->name);
	if (data->perm_type[0] == 'l')
		ft_printf(" -> {purple}%s{eoc}", data->link_name);
	ft_printf("\n");
}

void	print_arb(t_tree *tree, char flags)
{
	if (tree->left == NULL)
	{
		if (tree->data->name[0] != '.' || A & flags)
		{
			flags & L ? print_l_mode(tree->data)
				: ft_printf("%s\n", tree->data->name);
		}
		if (tree->right != NULL)
			print_arb(tree->right, flags);
	}
	else
	{
		print_arb(tree->left, flags);
		if (tree->data->name[0] != '.' || A & flags)
		{
			flags & L ? print_l_mode(tree->data)
				: ft_printf("%s\n", tree->data->name);
		}
		if (tree->right != NULL)
			print_arb(tree->right, flags);
	}
}
