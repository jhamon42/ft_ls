/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:53:19 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/22 18:23:00 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str, const void *strc, size_t n)
{
	size_t			i;
	unsigned char	*ptstr;
	unsigned char	*ptstrc;

	ptstr = str;
	ptstrc = (void *)strc;
	i = 0;
	while (i < n)
	{
		ptstr[i] = ptstrc[i];
		i++;
	}
	return (ptstr);
}
