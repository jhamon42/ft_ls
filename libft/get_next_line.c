/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 06:19:41 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 16:00:34 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_jdm(int fd, char **line, char **str, char *buffer)
{
	char	*tmp;
	int		kapa;
	int		i;

	ft_bzero(buffer, BUFF_SIZE);
	ft_memdel((void *)&str[fd]);
	str[fd] = ft_memalloc(BUFF_SIZE * sizeof(char) + 1);
	kapa = read(fd, buffer, BUFF_SIZE);
	if (kapa < 0)
		return (-1);
	else if (kapa == 0)
	{
		ft_memdel((void *)&buffer);
		ft_memdel((void *)&str[fd]);
		if (**line)
			return (-2);
		return (-3);
	}
	i = -1;
	while (buffer[++i] != '\n' && (i < kapa))
		str[fd][i] = buffer[i];
	tmp = *line;
	*line = ft_strjoin(tmp, str[fd]);
	ft_memdel((void *)&tmp);
	return (i);
}

static int	ft_match_n(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] != '\n')
		return (0);
	return (1);
}

static int	ft_resolve(int fd, char **line, char **str)
{
	char	*buffer;
	char	*tmp;
	int		i;

	i = 2;
	buffer = ft_memalloc(BUFF_SIZE * sizeof(char) + 1);
	while (i >= 0 && ft_match_n(buffer) != 1)
		i = ft_jdm(fd, line, str, buffer);
	if (i == -2)
		return (1);
	if (i == -3)
		return (0);
	if (i == -1)
		return (i);
	tmp = str[fd];
	str[fd] = ft_strsub(buffer, i + 1, (BUFF_SIZE - i));
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&buffer);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	**str;
	int			i;

	i = 0;
	if (fd < 0 || !line || fd > OPEN_MAX || BUFF_SIZE < 0)
		return (-1);
	if (!str)
		str = ft_memalloc(OPEN_MAX * sizeof(**str) + 1);
	if (!str[fd])
		str[fd] = ft_memalloc(BUFF_SIZE * sizeof(char) + 1);
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	if (str[fd][i] == '\n')
	{
		str[fd] = ft_strsub(str[fd], i + 1, (ft_strlen(str[fd]) - i));
		return (1);
	}
	return (ft_resolve(fd, line, str));
}
