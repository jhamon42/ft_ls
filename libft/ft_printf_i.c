/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:26:00 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:30 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_plumo(long long num, t_list *var, int y)
{
	int len;

	if (y == 1)
	{
		if (num >= 0 && var->plus == 1)
		{
			var->plus--;
			ft_copyinbuff('+', var);
			var->champ--;
		}
		else if (num < 0)
		{
			ft_copyinbuff('-', var);
			var->champ--;
		}
		else
			return (0);
		return (1);
	}
	len = ft_compt(num, 10);
	len = (len > var->precision) ? len : var->precision;
	len = ((num < 0) || (var->plus && num >= 0) || var->esp) ? len += 1 : len;
	len = (var->precision == 0 && num == 0) ? len -= 1 : len;
	return (len);
}

static void			ft_champetre(char c, t_list *var, int *len)
{
	int i;

	if (!var->moin && c == '0' && var->precision < 0)
		*len = var->champ;
	i = var->champ - *len;
	if (i > 0)
	{
		while (i--)
			ft_copyinbuff(c, var);
	}
}

static long long	ft_asgnum(long long num, t_list *var)
{
	if (var->l == 1 || var->h == 1 || var->j)
	{
		if (var->l || var->h)
			num = (var->l) ? (long int)num : (short)num;
		else
			num = (intmax_t)num;
	}
	else if (var->l == 2 || var->h == 2 || var->z)
	{
		if (var->l || var->h)
			num = (var->l) ? (long long)num : (char)num;
		else
			num = (size_t)num;
	}
	else
		num = (int)num;
	return (num);
}

static void			ft_itoab_bufff(long long nbr, t_list *var, int len)
{
	if ((--len > 0) || nbr >= 10 || nbr <= -10)
		ft_itoab_bufff(nbr / 10, var, len);
	nbr %= 10;
	if (nbr < 0)
		nbr *= -1;
	ft_copyinbuff(nbr + 48, var);
}

void				ft_printf_i(t_list *var, int i, void *item)
{
	int			len;
	long long	num;
	char		c;

	if (i == 1 && var->l != 2)
		return (ft_itoab_buff((int)item, 10, var));
	num = ft_asgnum((long long)item, var);
	len = ft_plumo(num, var, 0);
	(var->esp && !var->plus && num >= 0) ? ft_copyinbuff(' ', var) : 0;
	(var->esp && !var->plus && num >= 0) ? var->champ -= 1 : 0;
	(var->esp && !var->plus && num >= 0) ? len -= 1 : 0;
	c = (var->zero && !var->moin && var->precision < 0) ? '0' : ' ';
	if (var->moin)
	{
		len -= ft_plumo(num, var, 1);
		(len) ? ft_itoab_bufff(num, var, len) : 0;
	}
	ft_champetre(c, var, &len);
	if (!var->moin)
	{
		len -= ft_plumo(num, var, 1);
		(len) ? ft_itoab_bufff(num, var, len) : 0;
	}
}
