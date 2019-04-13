/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:26:14 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:57 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_compt(long long nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr >= 1 || nbr <= -1)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

int				ft_ucompt(unsigned long long nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr >= 1)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

void			ft_itoab_buff(long long nbr, int base, t_list *var)
{
	char	*bize;

	bize = "0123456789abcdefg";
	if (base <= 16 && base >= 2)
	{
		if ((--var->precision > 0) || nbr >= base || nbr <= -(base))
			ft_itoab_buff((nbr / base), base, var);
		if (nbr < 0 && nbr > -10 && base == 10)
		{
			ft_copyinbuff('-', var);
			nbr *= -1;
			ft_copyinbuff(bize[nbr % base], var);
		}
		else
		{
			nbr %= base;
			if (nbr < 0)
				nbr *= -1;
			ft_copyinbuff(bize[nbr], var);
		}
	}
}
