/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:26:00 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:22 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					ft_plumo(t_list *var)
{
	if (var->htag == 1)
	{
		var->htag--;
		ft_copyinbuff('0', var);
		if (var->precision != 0)
			var->precision--;
	}
}

static void					ft_champetre(char c, t_list *var, int len,\
	unsigned long long num)
{
	int i;

	i = var->champ - len;
	if (var->precision == 0 && num == 0 && !var->moin)
		i = var->champ;
	if (i > 0)
	{
		while (i)
		{
			ft_copyinbuff(c, var);
			i--;
		}
	}
}

static unsigned long long	ft_asgnum(unsigned long long num, t_list *var)
{
	if (var->l == 1 || var->h == 1 || var->j)
	{
		if (var->l || var->h)
			num = (var->l) ? (unsigned long int)num : (unsigned short)num;
		else
			num = (intmax_t)num;
	}
	else if (var->l == 2 || var->h == 2 || var->z)
	{
		if (var->l || var->h)
			num = (var->l) ? (unsigned long long)num : (unsigned char)num;
		else
			num = (size_t)num;
	}
	else
		num = (unsigned int)num;
	return (num);
}

static void					ft_itoab_bufff(unsigned long long nbr, t_list *var)
{
	if ((--var->precision > 0) || nbr >= 8)
		ft_itoab_bufff((nbr / 8), var);
	ft_copyinbuff((nbr % 8) + 48, var);
}

void						ft_printf_o(t_list *var, int i, void *item)
{
	unsigned long long	num;
	int					len;
	char				c;

	if (i == 1 && var->l == 0)
		return (ft_itoab_buff((unsigned int)item, 8, var));
	num = ft_asgnum((unsigned long long)item, var);
	len = ft_ucompt(num, 8);
	len = (len > var->precision) ? len : var->precision;
	len = (var->htag && num != 0) ? ++len : len;
	(var->htag && num == 0 && var->precision != 0) ? var->htag-- : 0;
	c = (var->zero && !var->moin && var->precision < 0) ? '0' : ' ';
	if (var->moin)
	{
		ft_plumo(var);
		(var->precision == 0 && num == 0) ? 0 : ft_itoab_bufff(num, var);
		ft_champetre(c, var, len, num);
	}
	else
	{
		ft_champetre(c, var, len, num);
		ft_plumo(var);
		(var->precision == 0 && num == 0) ? 0 : ft_itoab_bufff(num, var);
	}
}
