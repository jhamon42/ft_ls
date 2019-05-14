/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:57:27 by jhamon            #+#    #+#             */
/*   Updated: 2019/05/14 15:04:05 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		cp_data(
	struct stat *sb,
	struct passwd *pwd,
	struct group *grp,
	t_file *data)
{
	data->user_name = pwd->pw_name;
	data->group_name = grp->gr_name;
	data->link_number = sb->st_nlink;
	data->file_size = sb->st_size;
	ft_strncpy(data->last_modif, ctime(&sb->st_mtime) + 4, 12);
	data->time = sb->st_mtime;
	data->perm_type[0] = S_ISDIR(sb->st_mode) ? 'd' : '-';
	data->perm_type[0] = S_ISLNK(sb->st_mode) ? 'l' : data->perm_type[0];
	data->perm_type[0] = S_ISFIFO(sb->st_mode) ? 'p' : data->perm_type[0];
	data->perm_type[0] = S_ISCHR(sb->st_mode) ? 'c' : data->perm_type[0];
	data->perm_type[0] = S_ISSOCK(sb->st_mode) ? 's' : data->perm_type[0];
	data->perm_type[0] = S_ISBLK(sb->st_mode) ? 'b' : data->perm_type[0];
	data->perm_type[1] = sb->st_mode & S_IRUSR ? 'r' : '-';
	data->perm_type[2] = sb->st_mode & S_IWUSR ? 'w' : '-';
	data->perm_type[3] = sb->st_mode & S_IXUSR ? 'x' : '-';
	data->perm_type[4] = sb->st_mode & S_IRGRP ? 'r' : '-';
	data->perm_type[5] = sb->st_mode & S_IWGRP ? 'w' : '-';
	data->perm_type[6] = sb->st_mode & S_IXGRP ? 'x' : '-';
	data->perm_type[7] = sb->st_mode & S_IROTH ? 'r' : '-';
	data->perm_type[8] = sb->st_mode & S_IWOTH ? 'w' : '-';
	data->perm_type[9] = sb->st_mode & S_IXOTH ? 'x' : '-';
	data->major = major(sb->st_rdev);
	data->minor = minor(sb->st_rdev);
	data->perm_type[10] = '\0';
}

t_file			*create_data_file(char *dir_file)
{
	t_file			*data;
	struct stat		sb;
	struct passwd	*pwd;
	struct group	*grp;
	int				i;

	i = 0;
	if (!(data = malloc(sizeof(t_file))))
		exit_custum("malloc", EXIT_ERROR);
	ft_bzero(data, sizeof(t_file));
	if (lstat(dir_file, &sb) == -1)
		exit_custum("stat", EXIT_ERROR);
	if ((pwd = getpwuid(sb.st_uid)) == NULL)
		exit_custum("passwd", EXIT_ERROR);
	if ((grp = getgrgid(sb.st_gid)) == NULL)
		exit_custum("group", EXIT_ERROR);
	if (S_ISLNK(sb.st_mode)
		&& (i = readlink(dir_file, data->link_name, BUFSIZ)) == -1)
		exit_custum("readlink", EXIT_ERROR);
	cp_data(&sb, pwd, grp, data);
	data->link_name[i] = '\0';
	data->name = dir_file;
	return (data);
}
