/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:53:07 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/15 21:26:28 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**cpy_parms(const char **argv, int argc, int i, t_freemoi *eldoctor)
{
	char	**tmp;
	int		j;

	j = 0;
	if (argc - i)
	{
		if (!(tmp = ft_memalloc((argc - i + 1) * sizeof(char*))))
			free_consultation(eldoctor);
		while (argc > i)
			tmp[j++] = ft_strdup(argv[i++]);
		tmp[j] = NULL;
	}
	else
	{
		if (!(tmp = ft_memalloc(2 * sizeof(char*))))
			exit_custum("malloc", -1);
		tmp[j++] = ft_strdup(".");
		tmp[j] = NULL;
	}
	return (tmp);
}

void	parse_option(const char *flags, t_state_ls *ls)
{
	int i;

	i = 1;
	while (flags[i])
	{
		if (ls->match_flag[(int)flags[i]] == 0)
			exit_custum("flags", EXIT_ERROR);
		ls->flags = ls->flags | ls->match_flag[(int)flags[i++]];
	}
}
