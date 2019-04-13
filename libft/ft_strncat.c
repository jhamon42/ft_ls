/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:07:38 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/22 18:13:02 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *strc, size_t n)
{
	int		len_str;
	size_t	i;

	i = 0;
	len_str = ft_strlen(str);
	while (strc[i] && n > i)
	{
		str[len_str + i] = strc[i];
		i++;
	}
	str[len_str + i] = '\0';
	return (str);
}
