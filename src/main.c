/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/30 16:05:03 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc,const char *argv[])
{
	int			i;
	t_state_ls	ls;
	t_file		*file;
	char		**parms;

	i = 1;
	init_state_ls(&ls);
	if (argc > 2)
	{
		while (i < argc && argv[i][0] == '-')
			parse_option(argv[i++], &ls);
	}
	parms = cpy_parms(argv, argc, i);
	argc - i > 2 ? multi_print(parms, ls.flags) : simple_print(parms, ls.flags);
	return (0);
}
