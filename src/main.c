/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/06/04 16:09:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
	argc > 2 ? multi_print(tree, ls.flags) : simple_print(tree->data, ls.flags);
	return (0);
}
