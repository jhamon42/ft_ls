/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_while.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:18:24 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/06 15:02:05 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
/!\ ADD LE TABLEAU EN PARAM /!\ DONE
cree une data struct pour l'arbre bin DONE
add les elements du tableau en fonction du tri dans arb_bin
-> affichage
-> reparcoure recursif
-> free des elements arb_bin et data
return
*/
void recursive_while(char flags, int iterate, char **dir_files) {
  t_bin_tree  tree;

  ft_bzero(tree, sizeof(t_bin_tree));
  fild_tree(&tree, dir_files, flags);

}
