/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:53:07 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/30 16:50:24 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**cpy_parms(const char **argv, int argc, int i)
{
	char	**tmp;
	int		j;

	j = 0;
	if (argc - i)
	{
		if (!(tmp = ft_memalloc(argc - i + 1)))
			exit_custum("malloc", -1);
		while (argc > i)
			tmp[j++] = ft_strdup(argv[i++]);
	}
	else
	{
		if (!(tmp = ft_memalloc(2)))
			exit_custum("malloc", -1);
		tmp[j++] = ft_strdup(".");
	}
	return (tmp);
}

void	parse_option(const char *flags, t_state_ls *ls)
{
	int i;

	i = 1;
	while (flags[i])
	{
		if (ls->match_flag[flags[i]] == 0)
			exit_custum("flags", EXIT_ERROR);
		ls->flags = ls->flags | ls->match_flag[flags[i++]];
	}
}
