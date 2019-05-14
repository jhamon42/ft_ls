/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:03:00 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/13 15:03:17 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_state_ls(t_state_ls *ls)
{
	ft_bzero(ls, sizeof(t_state_ls));
	ft_bzero(ls->match_flag, 127);
	ls->match_flag['r'] = 16;
	ls->match_flag['R'] = 8;
	ls->match_flag['l'] = 4;
	ls->match_flag['a'] = 2;
	ls->match_flag['t'] = 1;
}
