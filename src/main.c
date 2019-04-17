/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/04/17 13:50:24 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void init_state_ls(t_state_ls *ls) {
  ls->flags = 0;
  ft_bzero(ls->match_flag, 127);
  ls->match_flag['r'] = 16;
  ls->match_flag['R'] = 8;
  ls->match_flag['l'] = 4;
  ls->match_flag['a'] = 2;
  ls->match_flag['t'] = 1;
}

int main(int argc, char const *argv[]) {
  int i;
  t_state_ls ls;

  i = 1;
  init_state_ls(&ls);
  argv[1] = argc < 2 ? "." : argv[1];
  while (i < argc && argv[i][0] == '-')
    parse_option(argv[i++] + 1, &ls);
  // prendre tous les arg
  return 0;
}
