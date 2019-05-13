/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/13 15:04:13 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char *argv[])
{
	int			i;
	t_state_ls	ls;

	i = 1;
	init_state_ls(&ls);
	argv[1] = argc < 2 ? "." : argv[1];
	while (i < argc && argv[i][0] == '-')
		parse_option(argv[i++] + 1, &ls);
	recursive_while(ls.flags, argc - i, argv + i);
	return (0);
}
