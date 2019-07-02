/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:47:47 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/02 16:48:33 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define CH(X) ft_printf("%50c-- check %d --\n", ' ', X)
# define A 2
# define L 4
# define T 1
# define R 16
# define GR 8
# define EXIT_ERROR -1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include "libft.h"

typedef struct		s_file {
	char			perm_type[11];
	char			*path;
	long int		link_number;
	char			*user_name;
	char			*group_name;
	long int		file_size;
	char			last_modif[13];
	int				minor;
	int				major;
	char			*name;
	long long int	block_alloc;
	long long int	time;
	char			link_name[BUFSIZ];
	short int		place;
}					t_file;

typedef struct		s_tree {
	struct s_tree	*left;
	struct s_tree	*right;
	long long int	tt_blocks;
	int				weight;
	t_file			*data;
}					t_tree;

/*
** flag encode in a char:
**           -r  -R -l -a -t
** [0][0][0][1] [1][1][1][1]
*/
typedef struct		s_state_ls {
	unsigned char	match_flag[127];
	char			flags;
}					t_state_ls;

typedef struct		s_freemoi {
	int				n_tree;
	t_tree			**trees;
	t_state_ls		*state;
}					t_freemoi;

void				parse_option(const char *flags, t_state_ls *ls);
void				recursive_while(char flags, t_tree *tree);
void				fild_tree(t_tree *tree, DIR *dir_files, char flags, char *path);
void				exit_custum(char *error, int type);
void				init_state_ls(t_state_ls *ls);
void				print_arb(t_tree *st, char flags);
void				simple_print(char *files, char flags);
void				multi_print(char **files, char flags);
void				print_l_mode(t_file *data);
void				sort_tree(t_tree *tmp, t_file *new_data, char flags);
void				free_tree(t_tree *tree);
char				**cpy_parms(const char **argv, int argc, int i);
t_file				*create_data_file(char *dir_file);
#endif
