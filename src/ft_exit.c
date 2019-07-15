/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:54:45 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/15 22:44:19 by jhamon           ###   ########.fr       */
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

	if (!(next = ft_memalloc(sizeof(t_freemoi))))
		free_consultation(eldoctor);
	next->pathology = patho;
	next->patient = *patient;
	next->next = eldoctor;
	eldoctor = next;
	return (eldoctor);
}

void		exit_custum(char *error, int type)
{
	perror(error);
	exit(type);
}
