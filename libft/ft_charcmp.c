/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:04:09 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:53 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_charcmp(int c, char const *s1)
{
	int				i;
	int				j;
	unsigned char	*str1;

	i = 0;
	j = -1;
	str1 = (unsigned char *)s1;
	while (str1[++j] != '\0')
		if (str1[j] == c)
			return (1);
	return (0);
}
