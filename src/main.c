/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/15 22:47:02 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, const char *argv[])
{
	int			i;
	char		**parms;
	t_freemoi	*eldoctor;
	t_state_ls	ls;

	i = 1;
	ft_printf("\n     START   \n\n----\n\n");
	init_state_ls(&ls);
	if (!(eldoctor = ft_memalloc(sizeof(t_freemoi))))
		free_consultation(eldoctor);
	while (i < argc && argv[i][0] == '-')
		parse_option(argv[i++], &ls);
	parms = cpy_parms(argv, argc, i, eldoctor);
	eldoctor->pathology = 1;
	eldoctor->patient = (void*)parms;
	eldoctor->next = NULL;
	argc - i > 1 ? multi_print(parms, ls.flags, eldoctor)
		: simple_print(parms[0], ls.flags, eldoctor);
	ft_printf("\n\n----\n\n");
	free_consultation(eldoctor);
	ft_printf("\n\n----\n\n");
	return (0);
}
