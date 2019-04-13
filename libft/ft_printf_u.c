/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:26:00 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:16 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					ft_champetre(char c, t_list *var, int len)
{
	int i;

	i = var->champ - len;
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
			num = (var->l) ? (unsigned long)num : (unsigned short)num;
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
	if ((--var->precision > 0) || nbr >= 10)
		ft_itoab_bufff((nbr / 10), var);
	ft_copyinbuff((nbr % 10) + 48, var);
}

void						ft_printf_u(t_list *var, int i, void *item)
{
	int					len;
	unsigned long long	num;
	char				c;

	if (i == 1 && var->l == 0)
		return (ft_itoab_buff((unsigned int)item, 10, var));
	num = ft_asgnum((unsigned long long)item, var);
	len = ft_ucompt(num, 10);
	len = (len > var->precision) ? len : var->precision;
	c = (var->zero && !var->moin && var->precision < 0) ? '0' : ' ';
	(var->moin) ? ft_itoab_bufff(num, var) : 0;
	ft_champetre(c, var, len);
	(var->moin || (var->precision == 0 && num == 0)) ? 0 : \
	ft_itoab_bufff(num, var);
}
