/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:45:35 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_copystr(t_list *var, char *str)
{
	int i;
	int tmp;

	i = 0;
	tmp = var->precision;
	if (!str)
		return (ft_copystr(var, "(null)"));
	while (str[i] && (var->precision-- != 0))
		ft_copyinbuff(str[i++], var);
	var->precision = tmp;
}

static void		ft_champgement(t_list *var, char c, int len)
{
	int i;

	i = var->champ - len;
	if (var->precision >= 0 && var->precision < len)
		i = (var->champ - var->precision);
	if (i > 0)
	{
		while (i)
		{
			ft_copyinbuff(c, var);
			i--;
		}
	}
}

void			ft_printf_s(t_list *var, int i, void *item)
{
	char c;

	if (var->l == 1)
		return (ft_printf_ss(var, i, item));
	if (i == 1 && item)
		return (ft_copystr(var, (char *)item));
	c = (var->zero && !var->moin) ? '0' : ' ';
	(var->moin) ? ft_copystr(var, (char *)item) : 0;
	(item) ? ft_champgement(var, c, ft_strlen((char *)item)) : \
			ft_champgement(var, c, 6);
	(!var->moin) ? ft_copystr(var, (char *)item) : 0;
}
