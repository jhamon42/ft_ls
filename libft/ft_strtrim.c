/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:50:06 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/27 15:14:51 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		len_s;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	len_s--;
	while ((s[len_s] == ' ' || s[len_s] == '\t' || s[len_s] == '\n') \
		&& len_s >= 0)
		len_s--;
	if (len_s == -1)
	{
		new_str = (char *)malloc(sizeof(char));
		new_str[0] = '\0';
		return (new_str);
	}
	if (!(new_str = (char *)malloc((len_s - i) * sizeof(char) + 1)))
		return (NULL);
	new_str = ft_strsub(s, i, (len_s - i + 1));
	return (new_str);
}
