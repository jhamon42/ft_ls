/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:53:30 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/25 05:56:51 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pts;
	unsigned char	cc;

	pts = (void *)s;
	cc = c;
	i = 0;
	while (i < n)
	{
		if ((pts[i] - cc) == 0)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
