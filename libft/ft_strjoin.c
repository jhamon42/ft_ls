/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:49:55 by jhamon            #+#    #+#             */
/*   Updated: 2018/02/20 12:25:32 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*new_str;

	i = -1;
	j = ft_strlen(s1);
	len = j + ft_strlen(s2);
	if (!(new_str = (char *)malloc((len + 1) * sizeof(char))) || !s1 || !s2)
		return (NULL);
	while (++i < j)
		new_str[i] = s1[i];
	j = -1; 
	while ((++j + i) < (len))
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	return (new_str);
}
