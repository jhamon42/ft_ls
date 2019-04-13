/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:10:12 by jhamon            #+#    #+#             */
/*   Updated: 2017/12/03 17:44:44 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int j;
	int boo;

	i = 1;
	j = 0;
	boo = 0;
	if (str[0] == '\0' && c == '\0')
		return ((char *)str);
	if (str[0] == c)
		boo = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	if (j == 0 && boo == 0)
		return (NULL);
	return ((char *)(str + j));
}
