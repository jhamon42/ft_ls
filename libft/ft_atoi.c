/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:10:54 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/27 13:01:40 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int num;

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
