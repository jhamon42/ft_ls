/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charnumb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 06:48:43 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:54 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_charnumb(char const *s1, int c)
{
	int				i;
	int				j;
	unsigned char	*str1;

	i = 0;
	j = -1;
	str1 = (unsigned char *)s1;
	while (str1[++j] != '\0')
		if (str1[j] == c)
			i++;
	return (i);
}
