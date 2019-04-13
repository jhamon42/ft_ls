/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:43:47 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:44:27 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi_ptf(const char *str)
{
	long long i;
	long long j;
	long long num;

	i = 0;
	j = -1;
	num = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || \
	str[i] == '\t' || str[i] == ' ' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (i > 18)
		num = j;
	if (j == 0)
		num *= -1;
	return (num);
}
