/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:44:49 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_copyinbuff(char c, t_list *var)
{
	if (var->curs == BUFF_SIZE)
	{
		write(1, &var->buff, BUFF_SIZE);
		var->rtrn += var->curs;
		var->curs = 0;
	}
	var->buff[var->curs++] = c;
	return (0);
}

int				ft_printf(const char *format, ...)
{
	static t_list	*var;
	static t_list	vuur;
	va_list			ap;
	int				i;

	i = -1;
	var = &vuur;
	va_start(ap, format);
	ft_lstinitcurs(var);
	while (format[++i])
	{
		if (format[i] == '{')
			i = i + ft_color((format + i), var);
		else if (format[i] == '%')
		{
			ft_lstinit(var);
			i = i + ft_care_is_me(format + i, var, ap);
		}
		else
			ft_copyinbuff(format[i], var);
	}
	var->rtrn += (var->curs != 0) ? \
		write(1, &var->buff, var->curs) : var->rtrn;
	va_end(ap);
	return (var->rtrn);
}
