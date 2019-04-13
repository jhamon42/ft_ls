/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:27:58 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:14 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	ft_matrix(int32_t a, int matrix)
{
	int32_t	b;

	b = (0x3f & a);
	b = (0xff & matrix) | b;
	b = (0x3f00 & (a << 2)) | b;
	b = (0xff00 & matrix) | b;
	b = (0x3f0000 & (a << 4)) | b;
	b = (0xff0000 & matrix) | b;
	b = (0x3f000000 & (a << 6)) | b;
	b = (0xff000000 & matrix) | b;
	return (b);
}

static void		ft_neobuff(int32_t c, int num, t_list *var)
{
	if (num)
		ft_neobuff(c >> 8, (num - 1), var);
	ft_copyinbuff((c & 0xff), var);
}

void			ft_put_wc(int32_t c, t_list *var)
{
	if (c <= 0x7f && c >= 0x0)
		ft_copyinbuff((char)c, var);
	else if (c <= 0x7ff && c >= 0x80)
	{
		c = ft_matrix(c, 0xC080);
		ft_neobuff(c, 1, var);
	}
	else if (c <= 0xffff && c >= 0x800)
	{
		c = ft_matrix(c, 0xE08080);
		ft_neobuff(c, 2, var);
	}
	else if (c <= 0xfffff && c >= 0x10000)
	{
		c = ft_matrix(c, 0xF0808080);
		ft_neobuff(c, 3, var);
	}
}
