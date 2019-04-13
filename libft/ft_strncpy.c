/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:54:54 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/22 18:13:09 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str, const char *strc, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (char)strc[i] != '\0')
	{
		str[i] = (char)strc[i];
		i++;
	}
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
