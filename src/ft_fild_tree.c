/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fild_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:43:25 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/06 15:57:47 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file *create_data_file(char *dir_file) {
  t_file *data;

  if (!(data = malloc(sizeof(t_file)))) {
    printf("ERROR\n");
    exit(1);
  }
  ft_bzero(data, sizeof(t_file));
  return(data);
}

static t_bin_tree *add_leaf(t_file *new_data) {
  t_bin_tree *new_branch;

  if (!(new_branch = malloc(sizeof(t_bin_tree))))
  {
    printf("ERROR\n");
    exit(1);
  }
  ft_bzero(new_branch, sizeof(t_bin_tree));
  new_branch->data = new_data;
  return(new_branch);
}

void fild_tree(t_bin_tree *tree, char **dir_files, char flags) {
  int i;
  t_bin_tree *tmp;
  t_file *new_data;

  i = 0;
  while(dir_files[i]) {
    tmp = tree;
    new_data = create_data_file(dir_files[i]);
    while(tmp->data != NULL) {
      if (ls->flags & T) {
        if (tmp->data->time > new_data->time) {
          if (tmp->right != NULL)
            tmp = tmp->right;
          else
            tmp->right = add_leaf(new_data);
        }
        else {
          if (tmp->left != NULL)
            tmp = tmp->left;
          else
            tmp->left = add_leaf(new_data);
        }
      }
    }
    i++;
  }
}
