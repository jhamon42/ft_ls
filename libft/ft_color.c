/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:13:23 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 19:09:27 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_oke(char *balise, t_list *var, int x)
{
	int i;

	i = 0;
	if (var->curs)
		write(1, &var->buff, var->curs);
	var->curs = 0;
	while (balise[i])
	{
		write(1, &balise[i], 1);
		i++;
	}
	return (x - 1);
}

static	int	ft_color2(const char *balise, t_list *var)
{
	if (ft_strequ(balise, "{YELLOW"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(YELLOW, var, 8)));
	else if (ft_strequ(balise, "{CYAN"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(CYAN, var, 6)));
	return ((ft_memdel_zero((void *)&balise) + ft_copyinbuff('{', var)));
}

int			ft_color(const char *format, t_list *var)
{
	char	*balise;
	int		i;

	i = 0;
	while (format[i] != '}' && format[i])
		i++;
	balise = ft_strsub(format, 0, i);
	ft_strupper(balise);
	if (i > 7 || i < 4 || format[i] != '}')
		return (ft_copyinbuff('{', var));
	if (ft_strequ(balise, "{EOC"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(EOC, var, 5)));
	else if (ft_strequ(balise, "{BLUE"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(BLUE, var, 6)));
	else if (ft_strequ(balise, "{BLACK"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(BLACK, var, 7)));
	else if (ft_strequ(balise, "{GREEN"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(GREEN, var, 7)));
	else if (ft_strequ(balise, "{GREY"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(GREY, var, 6)));
	else if (ft_strequ(balise, "{PURPLE"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(PURPLE, var, 8)));
	else if (ft_strequ(balise, "{RED"))
		return ((ft_memdel_zero((void *)&balise) + ft_oke(RED, var, 5)));
	return (ft_color2(balise, var));
}
