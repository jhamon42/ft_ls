/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:59:06 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/28 11:54:58 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	size_t				j;
	unsigned char		*s1;
	unsigned char		*s2;

	i = 0;
	j = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i == 0 && (s1[j] != '\0' || s2[j] != '\0') && n > j)
	{
		i = s1[j] - s2[j];
		j++;
	}
	if (s1[0] == '\0' && s2[0] != '\0')
		return (-1);
	if (s2[0] == '\0' && s1[0] != '\0')
		return (1);
	return (i);
}
