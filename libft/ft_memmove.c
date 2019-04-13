/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:52:54 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/25 05:43:03 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str, const void *strc, size_t n)
{
	unsigned char	*ptstr;
	unsigned char	*ptstrc;

	ptstr = str;
	ptstrc = (void *)strc;
	if (ptstrc < ptstr)
	{
		while (n != 0)
		{
			n--;
			ptstr[n] = ptstrc[n];
		}
	}
	else
		ft_memcpy(str, strc, n);
	return (ptstr);
}
