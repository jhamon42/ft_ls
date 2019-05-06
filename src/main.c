/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:01 by jhamon            #+#    #+#             */
/*   Updated: 2019/04/26 15:41:51 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void init_state_ls(t_state_ls *ls) {
  ft_bzero(ls, sizeof(t_state_ls));
  ft_bzero(ls->match_flag, 127);
  ls->match_flag['r'] = 16;
  ls->match_flag['R'] = 8;
  ls->match_flag['l'] = 4;
  ls->match_flag['a'] = 2;
  ls->match_flag['t'] = 1;
}

int main(int argc, char *argv[]) {
  int         i;
  t_state_ls  ls;

  i = 1;
  init_state_ls(&ls);
  argv[1] = argc < 2 ? "." : argv[1];
  while (i < argc && argv[i][0] == '-')
    parse_option(argv[i++] + 1, &ls);
  recursive_while(ls.flags, argc - i, argv + i);
  return 0;
}
