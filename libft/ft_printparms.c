/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printparms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:39:34 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:14 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_fail(t_list *var, int i, char item)
{
	if (item)
	{
		if (i != 1)
		{
			if (var->champ > 1)
			{
				if (var->moin == 1)
				{
					ft_copyinbuff(item, var);
					while (--var->champ)
						ft_copyinbuff(' ', var);
					return ;
				}
				else if (var->zero == 1)
				{
					while (--var->champ)
						ft_copyinbuff('0', var);
					return ((void)ft_copyinbuff(item, var));
				}
				while (--var->champ)
					ft_copyinbuff(' ', var);
			}
		}
		ft_copyinbuff(item, var);
	}
}

static void	ft_printparms_a(const char *tmp, int i, t_list *var, va_list ap)
{
	if (ft_charcmp(tmp[i], "cCsS"))
	{
		if (tmp[i] == 'C' || tmp[i] == 'c')
			(tmp[i] == 'C') ? ft_printf_cc(var, i, va_arg(ap, void*)) : \
								ft_printf_c(var, i, va_arg(ap, void*));
		else
			(tmp[i] == 's') ? ft_printf_s(var, i, va_arg(ap, void*)) : \
								ft_printf_ss(var, i, va_arg(ap, void*));
	}
	else
	{
		if (tmp[i] == 'p' || tmp[i] == '%')
			(tmp[i] == 'p') ? ft_printf_p(var, i, va_arg(ap, void*)) : \
								ft_printf_pc(var, i);
		else
			ft_printf_c(var, i, va_arg(ap, void*));
	}
}

static void	ft_printparms_b(const char *tmp, int i, t_list *var, va_list ap)
{
	if (ft_charcmp(tmp[i], "ubB"))
		(tmp[i] == 'u') ? \
		ft_printf_u(var, i, va_arg(ap, void*)) : \
		ft_printf_b(var, i, ap);
	else
	{
		if (tmp[i] == 'X')
			ft_printf_x(var, i, va_arg(ap, void*), 2);
		else
		{
			ft_resetprset(var);
			var->l = 1;
			ft_printf_u(var, i, va_arg(ap, void*));
		}
	}
}

static void	ft_printparms_c(const char *tmp, int i, t_list *var, va_list ap)
{
	if (tmp[i] == 'x' || tmp[i] == 'O')
	{
		if (tmp[i] == 'x')
			ft_printf_x(var, i, va_arg(ap, void*), 1);
		else
		{
			ft_resetprset(var);
			var->l = 2;
			ft_printf_o(var, i, va_arg(ap, void*));
		}
	}
	else
	{
		ft_resetprset(var);
		var->l = 2;
		ft_printf_i(var, i, va_arg(ap, void*));
	}
}

void		ft_printparms(const char *tmp, int *i, t_list *var, va_list ap)
{
	if (ft_charcmp(tmp[*i], "idDoOxXuUbBcCsSpfF%"))
	{
		if (ft_charcmp(tmp[*i], "idDoOxXuUbB"))
		{
			if (ft_charcmp(tmp[*i], "idDoOx"))
			{
				if (ft_charcmp(tmp[*i], "ido"))
					(tmp[*i] == 'i' || tmp[*i] == 'd') ? \
					ft_printf_i(var, *i, va_arg(ap, void*)) : \
					ft_printf_o(var, *i, va_arg(ap, void*));
				else
					ft_printparms_c(tmp, *i, var, ap);
			}
			else
				ft_printparms_b(tmp, *i, var, ap);
		}
		else
			ft_printparms_a(tmp, *i, var, ap);
	}
	else
	{
		if (tmp[*i] != 0)
			return (ft_printf_fail(var, *i, tmp[*i]));
		return (ft_printf_fail(var, *i -= 1, 0));
	}
}
