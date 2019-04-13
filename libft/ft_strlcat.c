/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:39:03 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/22 18:26:39 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *str, const char *strc, unsigned long n)
{
	unsigned long	len_str;
	unsigned long	len_strc;

	len_str = ft_strlen(str);
	len_strc = ft_strlen((char *)strc);
	if (len_str + 1 > n)
		return (len_strc + n);
	str = ft_strncat(str, strc, n - len_str - 1);
	return (len_str + len_strc);
}
