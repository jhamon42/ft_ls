/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:30:25 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:31 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_champetre(char c, t_list *var, int len)
{
	int i;

	i = 0;
	if (var->champ > len)
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

void			ft_printf_cc(t_list *var, int i, void *item)
{
	int		len;
	char	c;

	if (i == 1)
		return (ft_put_wc((int32_t)item, var));
	len = ft_omeniokt((int32_t)item);
	c = (var->zero && !var->moin) ? '0' : ' ';
	(var->moin) ? ft_put_wc((int32_t)item, var) : 0;
	ft_champetre(c, var, len);
	(!var->moin) ? ft_put_wc((int32_t)item, var) : 0;
}
