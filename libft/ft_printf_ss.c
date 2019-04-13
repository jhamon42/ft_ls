/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:45:01 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:17 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_omeniokt(int32_t c)
{
	if (c <= 0x7f && c >= 0x0)
		return (1);
	else if (c <= 0x7ff && c >= 0x80)
		return (2);
	else if (c <= 0xffff && c >= 0x800)
		return (3);
	else
		return (4);
}

static void		ft_str_wc(int32_t *str, t_list *var)
{
	int i;
	int tmp;

	i = 0;
	tmp = var->precision;
	while (str[i] && (var->precision != 0))
	{
		if (var->precision > 0)
			if (!((var->precision -= ft_omeniokt(str[i])) >= 0))
				break ;
		ft_put_wc(str[i++], var);
	}
	var->precision = tmp;
}

static void		ft_champetre(char c, t_list *var, int len)
{
	int i;

	i = 0;
	if (var->champ || var->precision)
	{
		if (var->champ > len)
			i = var->champ - len;
		if (var->precision > 0 && var->precision < len)
			i = (var->champ - var->precision);
	}
	if (i > 0)
	{
		while (i)
		{
			ft_copyinbuff(c, var);
			i--;
		}
	}
}

static int		ft_strl(int32_t *c, t_list *var)
{
	int i;
	int v;
	int tmp;

	i = 0;
	v = 0;
	tmp = var->precision;
	while (c[v] && (var->precision != 0))
	{
		if (var->precision > 0)
			if (!((var->precision -= ft_omeniokt(c[v])) >= 0))
				break ;
		if (c[v] <= 0x7f && c[v] >= 0x0)
			i += 1;
		else if (c[v] <= 0x7ff && c[v] >= 0x80)
			i += 2;
		else if (c[v] <= 0xffff && c[v] >= 0x800)
			i += 3;
		else
			i += 4;
		v++;
	}
	var->precision = tmp;
	return (i);
}

void			ft_printf_ss(t_list *var, int i, void *item)
{
	int len;

	if (!item)
		return (ft_str_wc(L"(null)", var));
	if (i != 1)
	{
		len = ft_strl((int32_t *)item, var);
		if (!var->moin)
		{
			if (var->zero)
				ft_champetre('0', var, len);
			else
				ft_champetre(' ', var, len);
			ft_str_wc((int32_t *)item, var);
		}
		else
		{
			ft_str_wc((int32_t *)item, var);
			ft_champetre(' ', var, len);
		}
		return ;
	}
	ft_str_wc((int32_t *)item, var);
}
