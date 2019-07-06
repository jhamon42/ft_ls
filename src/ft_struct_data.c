/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:57:27 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/06 21:00:00 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			prem_type_field(struct stat *sb, t_file *data)
{
	data->perm_type[0] = S_ISDIR(sb->st_mode) ? 'd' : '-';
	data->perm_type[0] = S_ISLNK(sb->st_mode) ? 'l' : data->perm_type[0];
	data->perm_type[0] = S_ISFIFO(sb->st_mode) ? 'p' : data->perm_type[0];
	data->perm_type[0] = S_ISCHR(sb->st_mode) ? 'c' : data->perm_type[0];
	data->perm_type[0] = S_ISSOCK(sb->st_mode) ? 's' : data->perm_type[0];
	data->perm_type[0] = S_ISBLK(sb->st_mode) ? 'b' : data->perm_type[0];
	data->perm_type[1] = sb->st_mode & S_IRUSR ? 'r' : '-';
	data->perm_type[2] = sb->st_mode & S_IWUSR ? 'w' : '-';
	data->perm_type[3] = sb->st_mode & S_IXUSR ? 'x' : '-';
	data->perm_type[3] = sb->st_mode & S_ISUID ? 'S' : data->perm_type[3];
	data->perm_type[3] = (sb->st_mode & S_ISUID) && (sb->st_mode & S_IXUSR)
		? 's' : data->perm_type[3];
	data->perm_type[4] = sb->st_mode & S_IRGRP ? 'r' : '-';
	data->perm_type[5] = sb->st_mode & S_IWGRP ? 'w' : '-';
	data->perm_type[6] = sb->st_mode & S_IXGRP ? 'x' : '-';
	data->perm_type[6] = sb->st_mode & S_ISGID ? 'S' : data->perm_type[6];
	data->perm_type[6] = (sb->st_mode & S_ISGID) && (sb->st_mode & S_IXGRP)
		? 's' : data->perm_type[6];
	data->perm_type[7] = sb->st_mode & S_IROTH ? 'r' : '-';
	data->perm_type[8] = sb->st_mode & S_IWOTH ? 'w' : '-';
	data->perm_type[9] = sb->st_mode & S_IXOTH ? 'x' : '-';
	data->perm_type[9] = sb->st_mode & S_ISVTX ? 'T' : data->perm_type[9];
	data->perm_type[9] = (sb->st_mode & S_ISVTX) && (sb->st_mode & S_IXOTH)
		? 't' : data->perm_type[9];
	data->perm_type[10] = '\0';
}

static void		cp_data(struct stat *sb, t_file *data, char* dir_file)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(sb->st_uid);
	grp = getgrgid(sb->st_gid);
	data->user_name = pwd ? pwd->pw_name : ft_itoa(sb->st_uid);
	data->group_name = grp ? grp->gr_name : ft_itoa(sb->st_gid);
	data->link_number = sb->st_nlink;
	data->file_size = sb->st_size;
	ft_strncpy(data->last_modif, ctime(&sb->st_mtime) + 4, 12);
	data->time = sb->st_mtime;
	prem_type_field(sb, data);
	data->major = major(sb->st_rdev);
	data->minor = minor(sb->st_rdev);
	data->block_alloc = sb->st_blocks;
	data->name = ft_strrchr(dir_file, '/');
	data->name = data->name ? data->name + 1 : dir_file;
	data->path = dir_file[ft_strlen(dir_file) - 1] == '/'
		? dir_file : ft_strjoin(dir_file, "/");
}

t_file			*create_data_file(char *dir_file)
{
	t_file			*data;
	struct stat		sb;
	int				i;

	i = 0;
	if (!(data = ft_memalloc(sizeof(t_file))))
		exit_custum("malloc", EXIT_ERROR); //
	if (lstat(dir_file, &sb) == -1)
	{
		perror(dir_file); // hey il faut faire un truc ici ^^
		ft_memdel((void*)&data);
		return (NULL);
	}
	else
	{
		if (S_ISLNK(sb.st_mode)
			&& (i = readlink(dir_file, data->link_name, BUFSIZ)) == -1)
			perror("readlink");
		data->link_name[i] = '\0';
		cp_data(&sb, data, dir_file);
	}
	return (data);
}
