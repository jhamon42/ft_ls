/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetprset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:03:57 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:13 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_resetprset(t_list *var)
{
	var->h = 0;
	var->l = 0;
	var->lm = 0;
	var->j = 0;
	var->z = 0;
}

void	ft_lstinitcurs(t_list *li)
{
	li->curs = 0;
	li->rtrn = 0;
}

void	ft_lstinit(t_list *li)
{
	li->l = 0;
	li->h = 0;
	li->lm = 0;
	li->j = 0;
	li->z = 0;
	li->esp = 0;
	li->zero = 0;
	li->moin = 0;
	li->plus = 0;
	li->htag = 0;
	li->champ = 0;
	li->precision = -1;
}

void	ft_offplace(char tmp, t_list *var)
{
	if (tmp == 'q' || tmp == 'L')
	{
		if (tmp == 'L')
			var->lm = 1;
		else
			var->l = 2;
	}
	else
	{
		if (tmp == 'j')
			var->j = 1;
		else
			var->z = 1;
	}
}
