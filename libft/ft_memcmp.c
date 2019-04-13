/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:53:25 by jhamon            #+#    #+#             */
/*   Updated: 2017/12/03 18:30:02 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pts1;
	unsigned char	*pts2;
	size_t			temp;

	pts1 = (void *)s1;
	pts2 = (void *)s2;
	i = 0;
	temp = 0;
	while (i < n && temp == 0)
	{
		temp = pts1[i] - pts2[i];
		i++;
	}
	return (temp);
}
