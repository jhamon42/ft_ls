/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:35:48 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/15 23:06:06 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	is_dir(t_apaletemps	*plt, t_freemoi *eldoctor)
{
	DIR			*dir;
	t_tree		*tree;

	if ((tree = ft_memalloc(sizeof(t_tree))) == NULL)
		exit_custum("malloc", -1);
	eldoctor = add_patient(eldoctor, (void*)&tree, 2);
	dir = opendir(plt->data->path);
	plt->tree = tree;
	if (dir != NULL)
	{
		fild_tree(dir, plt->data->path, plt, eldoctor);
		closedir(dir);
		L & plt->flags && (tree->weight > 1)
			? ft_printf("total %lld\n", tree->tt_blocks) : 0;
		print_arb(tree, plt->flags);
	}
	if (plt->flags & GR)
		recursive_while(plt->flags, tree, eldoctor);
	eldoctor = free_patient(eldoctor);
	ft_printf("\n\nayfba\n\n");
}

void			simple_print(char *files, char flags, t_freemoi *eldoctor)
{
	t_file			*data;
	t_apaletemps	plt;

	data = create_data_file(files, eldoctor);
	plt.data = data;
	plt.flags = flags;
	if (data && data->perm_type[0] != 'd')
	{
		flags & L ? print_l_mode(data)
			: ft_printf("%s\n", data->name);
		free_data(data);
	}
	else if (data)
	{
		is_dir(&plt, eldoctor);
		free_data(data);
	}
	// ft_printf("->%d\n", eldoctor->pathology);
}
