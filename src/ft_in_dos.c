/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_dos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:57:22 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/18 16:57:29 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	for_place(
	t_file *data,
	DIR *dir,
	t_apaletemps *plt,
	t_freemoi *eldoctor)
{
	t_tree			*tree_tmp;

	if ((tree_tmp = ft_memalloc(sizeof(t_tree))) == NULL)
		exit_custum("malloc", -1, eldoctor);
	add_patient(&eldoctor, (void*)&tree_tmp, 2);
	plt->tree = tree_tmp;
	fild_tree(dir, data->path, plt, eldoctor);
	closedir(dir);
	L & plt->flags && ((tree_tmp->weight > 1) || A & plt->flags)
		? ft_printf("total %lld\n", tree_tmp->tt_blocks) : 0;
	print_arb(tree_tmp, plt->flags);
	if (plt->flags & GR)
		recursive_while(plt->flags, tree_tmp, eldoctor);
	free_patient(&eldoctor);
}

void	in_dos(t_tree *tree, char flags, t_freemoi *eldoctor)
{
	DIR				*dir;
	t_file			*data;
	t_apaletemps	plt;

	dir = NULL;
	plt.flags = flags;
	if ((data = create_data_file(tree->data->name, eldoctor)) != NULL)
	{
		add_patient(&eldoctor, (void*)&data, 3);
		if ((dir = opendir(data->path)))
			for_place(data, dir, &plt, eldoctor);
		else
		{
			write(2, "./ft_ls: ", 9);
			perror(data->name);
		}
		free_patient(&eldoctor);
	}
}
