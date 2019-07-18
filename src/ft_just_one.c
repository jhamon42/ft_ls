/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:35:48 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/18 16:31:36 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	is_dir(t_apaletemps *plt, t_freemoi *eldoctor)
{
	DIR			*dir;
	t_tree		*tree;

	if ((dir = opendir(plt->data->path)))
	{
		if ((tree = ft_memalloc(sizeof(t_tree))) == NULL)
			exit_custum("malloc", EXIT_ERROR, eldoctor);
		add_patient(&eldoctor, (void*)&tree, 2);
		plt->tree = tree;
		fild_tree(dir, plt->data->path, plt, eldoctor);
		closedir(dir);
		L & plt->flags && ((tree->weight > 1) || A & plt->flags)
			? ft_printf("total %lld\n", tree->tt_blocks) : 0;
		print_arb(tree, plt->flags);
		if (plt->flags & GR)
			recursive_while(plt->flags, tree, eldoctor);
		free_patient(&eldoctor);
	}
	else
	{
		write(2, "./ft_ls: ", 9);
		perror(plt->data->name);
	}
}

void			simple_print(char *files, char flags, t_freemoi *eldoctor)
{
	t_file			*data;
	t_apaletemps	plt;

	if ((data = create_data_file(files, eldoctor)))
	{
		add_patient(&eldoctor, (void*)&data, 3);
		plt.data = data;
		plt.flags = flags;
		if (data->perm_type[0] != 'd')
		{
			flags & L ? print_l_mode(data)
				: ft_printf("%s\n", data->name);
			free_patient(&eldoctor);
		}
		else
		{
			is_dir(&plt, eldoctor);
			free_patient(&eldoctor);
		}
	}
}
