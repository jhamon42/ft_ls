/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:54:13 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/25 07:05:25 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *chrch)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((str[i] == '\0' && chrch[i] == '\0') || chrch[i] == '\0')
		return ((char *)(str));
	while (str[i])
	{
		while (str[i] == chrch[j])
		{
			j++;
			if (chrch[j] == '\0')
				return ((char *)(str + (i + 1) - j));
			i++;
		}
		if (j != 0)
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
