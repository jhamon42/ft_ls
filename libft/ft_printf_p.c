/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:26:00 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:20 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_plumo(t_list *var)
{
	if (var->htag == 1)
	{
		var->htag--;
		ft_copyinbuff('0', var);
		ft_copyinbuff('x', var);
	}
}

static void			ft_champetre(char c, t_list *var, int len)
{
	int i;

	i = var->champ - len;
	if (i > 0)
	{
		if (c == '0')
			ft_plumo(var);
		while (i)
		{
			ft_copyinbuff(c, var);
			i--;
		}
	}
}

static void			ft_itoab_bufff(long long nbr, int base, t_list *var)
{
	char		*bize;

	bize = "0123456789abcdefg";
	if (base <= 16 && base >= 2)
	{
		if ((--var->precision > 0) || nbr >= base)
			ft_itoab_bufff((nbr / base), base, var);
		ft_copyinbuff(bize[nbr % base], var);
	}
}

void				ft_printf_p(t_list *var, int i, void *item)
{
	int		len;
	char	c;

	if (i)
	{
		len = ft_ucompt((unsigned long)item, 16);
		len = (len > var->precision) ? len : var->precision;
		len += 2;
		var->htag = 1;
		c = (var->zero && !var->moin) ? '0' : ' ';
		if (var->moin)
		{
			ft_plumo(var);
			ft_itoab_bufff((unsigned long)item, 16, var);
		}
		ft_champetre(c, var, len);
		if (!var->moin)
		{
			ft_plumo(var);
			if (var->precision != 0)
				ft_itoab_bufff((unsigned long)item, 16, var);
		}
	}
}
