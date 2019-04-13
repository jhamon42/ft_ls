/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:26:00 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 19:15:08 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_prtbit(unsigned long value, int taille, t_list *var)
{
	int i;

	i = taille;
	while (--i >= 0)
	{
		ft_copyinbuff(((value >> i) & 1) + 48, var);
		if (!(i % 4) && i != 0)
			ft_copyinbuff(' ', var);
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

void				ft_printf_b(t_list *var, int i, va_list ap)
{
	float				num_f;
	long long			num;
	unsigned long		b;
	int					c;

	c = 32;
	if (i == 1)
		return (ft_prtbit(va_arg(ap, long long), c, var));
	if (var->lm == 1)
	{
		num_f = va_arg(ap, double);
		b = *(int *)&num_f;
		ft_prtbit(b, 32, var);
	}
	else
	{
		num = va_arg(ap, long long);
		num = ft_asgnum(num, var);
		if (var->l || var->j || var->z)
			c = 64;
		if (var->h)
			c = (var->h == 1) ? 16 : 8;
		b = num;
		ft_prtbit(b, c, var);
	}
}
