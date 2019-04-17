/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:53:07 by jhamon            #+#    #+#             */
/*   Updated: 2019/04/17 13:40:13 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void parse_option(const char* flags, t_state_ls *ls) {
  int i = 0;
  while(flags[i])
  {
    if (ls->match_flag[flags[i]] == 0)
      exit(EXIT_SUCCESS);
    ls->flags = ls->flags | ls->match_flag[flags[i++]];
  }
}
