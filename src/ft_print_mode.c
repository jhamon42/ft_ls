/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:44:08 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/14 12:23:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	print_arb(t_tree *st)
{
	if (st->left == NULL)
	{
		print_l_mode(st->data);
		if (st->right != NULL)
			print_arb(st->right);
	}
	else
	{
		print_arb(st->left);
		print_l_mode(st->data);
		if (st->right != NULL)
			print_arb(st->right);
	}
}
