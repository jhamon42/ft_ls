/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:50:13 by jhamon            #+#    #+#             */
/*   Updated: 2017/11/28 11:20:36 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		lettre_is(int i, char const *s, char c)
{
	int i_lettre;

	i_lettre = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i_lettre++;
		i++;
	}
	return (i_lettre);
}

static	void	tab_init(char **tab, char const *s, char c)
{
	int i;
	int i_mot;

	i = 0;
	i_mot = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			if (!(tab[i_mot] = (char *)malloc(lettre_is(i, s, c) * \
				sizeof(char) + 1)))
				return ;
			tab[i_mot] = ft_strdup(ft_strsub(s, i, lettre_is(i, s, c)));
			i += lettre_is(i, s, c);
			i_mot++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
}

static	int		mot_is(char const *s, char c)
{
	int		i_mot;
	int		i;

	i_mot = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			i_mot++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (i_mot);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i_mot;

	if (!s)
		return (NULL);
	i_mot = mot_is(s, c);
	if (!(tab = (char **)malloc(i_mot * sizeof(char *) + 1)))
		return (NULL);
	tab[i_mot] = NULL;
	tab_init(tab, s, c);
	return (tab);
}
