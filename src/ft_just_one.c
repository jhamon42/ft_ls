/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:35:48 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/06 14:57:49 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	is_dir(t_apaletemps	*plt)
{
	DIR			*dir;
	t_tree		*tree;

	if ((tree = ft_memalloc(sizeof(t_tree))) == NULL)
		exit_custum("malloc", -1);
	plt->eldoctor = add_patient(plt->eldoctor, (void*)&tree, 2);
	dir = opendir(plt->data->path);
	plt->tree = tree;
	if (dir != NULL)
	{
		fild_tree(dir, plt->data->path, plt);
		closedir(dir);
		L & plt->flags && (tree->weight > 1)
			? ft_printf("total %lld\n", tree->tt_blocks) : 0;
		print_arb(tree, plt->flags);
	}
	if (plt->flags & GR)
		recursive_while(plt->flags, tree, plt->eldoctor);
	// free_tree(tree);
}

void			simple_print(char *files, char flags, t_freemoi *eldoctor)
{
	t_file			*data;
	t_apaletemps	plt;

	plt.eldoctor = eldoctor;
	data = create_data_file(files);
	plt.data = data;
	plt.flags = flags;
	if (data && data->perm_type[0] != 'd')
	{
		flags & L ? print_l_mode(data)
			: ft_printf("%s\n", data->name);
		// ft_bzero(data, sizeof(t_file));
		// ft_memdel((void*)&data);
	}
	else if (data)
		is_dir(&plt);
}
