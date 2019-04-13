/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:34:16 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:45:16 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chapitre(t_list *var, char c)
{
	while (--var->champ)
		ft_copyinbuff(c, var);
}

void		ft_printf_c(t_list *var, int i, void *item)
{
	if (i != 1)
	{
		if (var->l == 1)
			return (ft_printf_cc(var, i, item));
		if (var->champ > 1)
		{
			if (var->moin == 1)
			{
				ft_copyinbuff((char)item, var);
				return (ft_chapitre(var, ' '));
			}
			else if (var->zero == 1)
			{
				ft_chapitre(var, '0');
				return ((void)ft_copyinbuff((char)item, var));
			}
			ft_chapitre(var, ' ');
		}
	}
	ft_copyinbuff((char)item, var);
}
