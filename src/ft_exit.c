/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:54:45 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/16 19:30:54 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		free_consultation(t_freemoi *eldoctor)
{
	t_freemoi	*curse;

	while (eldoctor)
	{
		curse = eldoctor;
		eldoctor = curse->next;
		curse->pathology == 3 ? free_data(curse->patient) : 0;
		curse->pathology == 2 ? free_tree(curse->patient) : 0;
		curse->pathology == 1 ? free_parms(curse->patient) : 0;
		ft_bzero(curse, sizeof(t_freemoi));
		ft_memdel((void*)&curse);
	}
}

void		add_patient(t_freemoi **eldoctor, void **patient, int patho)
{
	t_freemoi	*next;

	if (!(next = ft_memalloc(sizeof(t_freemoi))))
		free_consultation(*eldoctor);
	next->pathology = patho;
	next->patient = *patient;
	next->next = *eldoctor;
	*eldoctor = next;
}

void		exit_custum(char *error, int type, t_freemoi *eldoctor)
{
	free_consultation(eldoctor);
	write(2, "./ft_ls: ", 10);
	perror(error);
	exit(type);
}
