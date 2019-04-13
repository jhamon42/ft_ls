/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:53:35 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/28 13:48:02 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str, const void *strc, int c, size_t n)
{
	size_t				i;
	unsigned char		cc;
	unsigned char		*ptstr;
	const unsigned char	*ptstrc;

	if (!n)
		return (NULL);
	ptstr = str;
	ptstrc = strc;
	cc = c;
	i = 0;
	while (n != 0 || i == 0)
	{
		i = 1;
		if ((*ptstr++ = *ptstrc++) == cc)
			return (ptstr);
		n--;
	}
	return (NULL);
}
