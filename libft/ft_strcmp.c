/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:36:06 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/28 11:47:27 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *str1, char const *str2)
{
	int				i;
	int				j;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	j = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i == 0 && (s1[j] != '\0' || s2[j] != '\0'))
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
