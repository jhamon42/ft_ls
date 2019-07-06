/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:54:45 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/06 14:03:39 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		free_consultation(t_freemoi *eldoctor)
{
	t_freemoi	*curse;

	while (eldoctor)
	{
		if ((void*)&eldoctor->patient)
		{
			eldoctor->pathology == 3 && ((t_file*)eldoctor->patient)->name ? free_data((t_file*)&eldoctor->patient) : 0;
			eldoctor->pathology == 2 && ((t_tree*)eldoctor->patient)->data ? free_tree((t_tree*)&eldoctor->patient) : 0;
			eldoctor->pathology == 1 && (char**)eldoctor->patient ? free_parms((char**)&eldoctor->patient) : 0;
		}
		curse = eldoctor;
		eldoctor = eldoctor->next;
		ft_bzero(curse, sizeof(t_freemoi));
		ft_memdel((void*)&curse);
	}
}

/*
**	Pathology :
**
**	1 : parms
**	2 : tree
**	3 : data
*/
t_freemoi	*add_patient(t_freemoi *eldoctor, void **patient, int patho)
{
	t_freemoi	*next;

	eldoctor->pathology = patho;
	eldoctor->patient = *patient;
	if (!(next = ft_memalloc(sizeof(t_freemoi))))
		free_consultation(eldoctor);
	next->next = eldoctor;
	return (next);
}

void		exit_custum(char *error, int type)
{
	perror(error);
	exit(type);
}
