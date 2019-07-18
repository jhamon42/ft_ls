/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:57:27 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/17 18:38:57 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			prem_type_field(mode_t st_mode, t_file *data)
{
	data->perm_type[0] = S_ISDIR(st_mode) ? 'd' : '-';
	data->perm_type[0] = S_ISLNK(st_mode) ? 'l' : data->perm_type[0];
	data->perm_type[0] = S_ISFIFO(st_mode) ? 'p' : data->perm_type[0];
	data->perm_type[0] = S_ISCHR(st_mode) ? 'c' : data->perm_type[0];
	data->perm_type[0] = S_ISSOCK(st_mode) ? 's' : data->perm_type[0];
	data->perm_type[0] = S_ISBLK(st_mode) ? 'b' : data->perm_type[0];
	data->perm_type[1] = st_mode & S_IRUSR ? 'r' : '-';
	data->perm_type[2] = st_mode & S_IWUSR ? 'w' : '-';
	data->perm_type[3] = st_mode & S_IXUSR ? 'x' : '-';
	data->perm_type[3] = st_mode & S_ISUID ? 'S' : data->perm_type[3];
	data->perm_type[3] = (st_mode & S_ISUID) && (st_mode & S_IXUSR)
		? 's' : data->perm_type[3];
	data->perm_type[4] = st_mode & S_IRGRP ? 'r' : '-';
	data->perm_type[5] = st_mode & S_IWGRP ? 'w' : '-';
	data->perm_type[6] = st_mode & S_IXGRP ? 'x' : '-';
	data->perm_type[6] = st_mode & S_ISGID ? 'S' : data->perm_type[6];
	data->perm_type[6] = (st_mode & S_ISGID) && (st_mode & S_IXGRP)
		? 's' : data->perm_type[6];
	data->perm_type[7] = st_mode & S_IROTH ? 'r' : '-';
	data->perm_type[8] = st_mode & S_IWOTH ? 'w' : '-';
	data->perm_type[9] = st_mode & S_IXOTH ? 'x' : '-';
	data->perm_type[9] = st_mode & S_ISVTX ? 'T' : data->perm_type[9];
	data->perm_type[9] = (st_mode & S_ISVTX) && (st_mode & S_IXOTH)
		? 't' : data->perm_type[9];
	data->perm_type[10] = '\0';
}

static void		thetime(struct stat *sb, t_file *data)
{
	char			*tmp;

	tmp = ctime(&sb->st_mtime);
	if ((sb->st_mtime - (time(NULL) - 13046400)) < 0)
	{
		ft_strncpy(data->last_modif, tmp + 4, 7);
		ft_strncpy(data->last_modif + 7, tmp + 20, 4);
	}
	else
	{
		ft_strncpy(data->last_modif, tmp + 4, 12);
	}
	data->time = sb->st_mtime;
}

static void		cp_data(struct stat *sb, t_file *data, char *dir_file)
{
	data->user_name = ft_strdup(user_from_uid(sb->st_uid, 0));
	data->group_name = ft_strdup(group_from_gid(sb->st_gid, 0));
	data->link_number = sb->st_nlink;
	data->file_size = sb->st_size;
	thetime(sb, data);
	prem_type_field(sb->st_mode, data);
	data->major = major(sb->st_rdev);
	data->minor = minor(sb->st_rdev);
	data->block_alloc = sb->st_blocks;
	data->dir_file = ft_strdup(dir_file);
	data->name = ft_strrchr(data->dir_file, '/');
	data->name = data->name && data->name[1] != '\0'
		? data->name + 1 : data->dir_file;
	data->path = data->dir_file[ft_strlen(data->dir_file) - 1] == '/'
		? ft_strdup(data->dir_file) : ft_strjoin(data->dir_file, "/");
}

t_file			*create_data_file(char *dir_file, t_freemoi *eldoctor)
{
	t_file			*data;
	struct stat		sb;
	int				i;

	i = 0;
	if (!(data = ft_memalloc(sizeof(t_file))))
		exit_custum("malloc", EXIT_ERROR, eldoctor);
	if (lstat(dir_file, &sb) == -1)
	{
		write(2, "./ft_ls: ", 10);
		perror(dir_file);
		ft_memdel((void*)&data);
		return (NULL);
	}
	else
	{
		if (S_ISLNK(sb.st_mode)
			&& (i = readlink(dir_file, data->link_name, BUFSIZ)) == -1)
			perror(dir_file);
		data->link_name[i] = '\0';
		cp_data(&sb, data, dir_file);
	}
	return (data);
}
