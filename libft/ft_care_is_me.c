/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_care_is_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:00:57 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:53 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_prciflag(const char *tmp, int i, t_list *var, va_list ap)
{
	int j;

	j = i;
	var->precision = 0;
	while (ft_charcmp(tmp[i], "0123456789") || tmp[i] == '*')
	{
		if (tmp[i] == '*')
		{
			var->precision = va_arg(ap, int);
			i++;
		}
		else
		{
			while (ft_charcmp(tmp[i], "0123456789") && tmp[i])
				i++;
			var->precision = ft_atoi(tmp + j);
		}
	}
	return (i);
}

static int	ft_chmpflag(const char *tmp, int i, t_list *var, va_list ap)
{
	int j;

	j = i;
	if (tmp[i] == '*')
	{
		var->champ = va_arg(ap, int);
		var->moin = (var->champ < 0) ? 1 : var->moin;
		var->champ = (var->champ < 0) ? -(var->champ) : var->champ;
		i++;
	}
	else if (ft_charcmp(tmp[i], "0123456789"))
	{
		while (ft_charcmp(tmp[i], "0123456789") && tmp[i])
			i++;
		var->champ = ft_atoi(tmp + j);
	}
	return (i);
}

static int	ft_lastflags(const char *tmp, int i, t_list *var)
{
	ft_resetprset(var);
	if (tmp[i] == 'h')
	{
		var->h = 1;
		if (tmp[++i] == 'h')
		{
			var->h = 2;
			i++;
		}
	}
	else if (tmp[i] == 'l')
	{
		var->l = 1;
		if (tmp[++i] == 'l')
		{
			var->l = 2;
			i++;
		}
	}
	else
		ft_offplace(tmp[i++], var);
	return (i);
}

static int	ft_firstflag(const char *tmp, int i, t_list *var)
{
	while (ft_charcmp(tmp[i], " -+0#"))
	{
		if (tmp[i] == ' ' || tmp[i] == '#' || tmp[i] == '+')
		{
			if (tmp[i] == ' ')
				var->esp = 1;
			else
			{
				if (tmp[i] == '#')
					var->htag = 1;
				else
					var->plus = 1;
			}
		}
		else
		{
			if (tmp[i] == '-')
				var->moin = 1;
			else
				var->zero = 1;
		}
		i++;
	}
	return (i);
}

int			ft_care_is_me(const char *tmp, t_list *var, va_list ap)
{
	int i;

	i = 1;
	while (ft_charcmp(tmp[i], " -+0#qLjzlh.0123456789*") && tmp[i])
	{
		i = ft_firstflag(tmp, i, var);
		i = ft_chmpflag(tmp, i, var, ap);
		if (tmp[i] == '.')
			i = ft_prciflag(tmp, ++i, var, ap);
		if (ft_charcmp(tmp[i], "qLjzlh"))
			i = ft_lastflags(tmp, i, var);
	}
	ft_printparms(tmp, &i, var, ap);
	return (i);
}
