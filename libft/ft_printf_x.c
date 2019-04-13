/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:45:23 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:16 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					ft_champetre(char c, t_list *var, int len, int n)
{
	int i;

	i = var->champ - len;
	if (i > 0)
	{
		if (var->htag == 1 && c == '0')
		{
			var->htag--;
			ft_copyinbuff('0', var);
			(n == 2) ? ft_copyinbuff('X', var) : ft_copyinbuff('x', var);
		}
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
			num = (uintmax_t)num;
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

static void					ft_itoab_bufff(unsigned long long nbr, \
											t_list *var, int n)
{
	char		*bize;

	bize = (n == 2) ? "0123456789ABCDEFG" : "0123456789abcdefg";
	if (nbr == 0 && var->precision == 0)
		return ;
	if (var->htag-- == 1)
	{
		ft_copyinbuff('0', var);
		(n == 2) ? ft_copyinbuff('X', var) : ft_copyinbuff('x', var);
	}
	if ((--var->precision > 0) || nbr >= 16)
		ft_itoab_bufff((nbr / 16), var, n);
	ft_copyinbuff(bize[nbr % 16], var);
}

void						ft_printf_x(t_list *var, int i, void *item, int n)
{
	unsigned long long	num;
	int					len;
	char				c;

	if (i == 1)
	{
		if (n == 1)
			return (ft_itoab_buff((unsigned int)item, 16, var));
		return (ft_itoab_bufff((unsigned int)item, var, n));
	}
	num = ft_asgnum((unsigned long long)item, var);
	len = ft_ucompt(num, 16);
	len = (len > var->precision) ? len : var->precision;
	(var->htag && num != 0) ? len += 2 : 0;
	(var->htag && num == 0) ? var->htag-- : 0;
	(num == 0 && var->precision == 0) ? len-- : 0;
	c = (var->zero && !var->moin && var->precision < 0) ? '0' : ' ';
	(var->moin) ? ft_itoab_bufff(num, var, n) : 0;
	ft_champetre(c, var, len, n);
	(var->moin) ? 0 : \
		ft_itoab_bufff(num, var, n);
}
