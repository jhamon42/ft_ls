/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:17:18 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/25 07:17:40 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *chrch, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if ((str[i] == '\0' && chrch[i] == '\0') || chrch[i] == '\0')
		return ((char *)(str));
	while (str[i] && (i < len))
	{
		while (str[i] == chrch[j] && i < len)
		{
			j++;
			if (chrch[j] == '\0')
				return ((char *)(str + ((i + 1) - j)));
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
