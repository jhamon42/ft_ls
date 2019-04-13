/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:44 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/22 18:11:42 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str, const char *strc)
{
	int len_str;
	int i;

	i = 0;
	len_str = ft_strlen(str);
	while (strc[i])
	{
		str[len_str + i] = strc[i];
		i++;
	}
	str[len_str + i] = '\0';
	return (str);
}
