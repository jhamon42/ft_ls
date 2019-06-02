/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/02 14:46:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char *argv[])
{
	int			i;
	t_state_ls	ls;
	t_tree		*tree;

	i = 1;
	argv[1] = argc < 2 ? "." : argv[1];
	init_state_ls(&ls);
	if (!(tree = malloc(sizeof(t_tree))))
		exit_custum("malloc", EXIT_ERROR);
	ft_bzero(tree, sizeof(t_tree));
	while (i < argc && argv[i][0] == '-')
		parse_option(argv[i++] + 1, &ls);
	tree->data = create_data_file(argv[i++]);
	argc > 2 ? fild_tree(tree, argv + i, ls.flags) : 0;
	print_arb(tree, ls.flags, 1);
	argc - i ? recursive_while(ls.flags, argv + i) : 0;
	return (0);
}
