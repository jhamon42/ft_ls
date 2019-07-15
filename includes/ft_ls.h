/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:47:47 by jhamon            #+#    #+#             */
/*   Updated: 2019/07/15 22:45:30 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

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
# include <errno.h>
# include "libft.h"


typedef struct			s_file {
	int					major;
	int					minor;
	char				*path;
	char				*name;
	char				*user_name;
	char				*group_name;
	char				perm_type[11];
	char				last_modif[13];
	char				link_name[BUFSIZ];
	long int			file_size;
	long int			link_number;
	long long int		time;
	long long int		block_alloc;
}						t_file;

typedef struct			s_tree {
	int					weight;
	t_file				*data;
	struct s_tree		*left;
	struct s_tree		*right;
	long long int		tt_blocks;
}						t_tree;

/*
** flag encode in a char:
**       -1 -r  -R -l -a -t
** [0][0][1][1] [1][1][1][1]
*/
typedef struct			s_state_ls {
	char				flags;
	unsigned char		match_flag[127];
}						t_state_ls;

typedef struct			s_freemoi {
	int					pathology;
	void				*patient;
	struct s_freemoi	*next;
}						t_freemoi;

typedef	struct			s_apaletemps {
	char				flags;
	t_tree				*tree;
	t_file				*data;
}						t_apaletemps;

void					sort_tree(t_tree *tmp, t_file *new_data, char flags, t_freemoi *eldoctor);
void					recursive_while(char flags, t_tree *tree, t_freemoi *eldoctor);
void					simple_print(char *files, char flags, t_freemoi *eldoctor);
void					multi_print(char **files, char flags, t_freemoi *eldoctor);
void					fild_tree(DIR *dir_files, char *path, t_apaletemps *plt, t_freemoi *eldoctor);
void					parse_option(const char *flags, t_state_ls *ls);
void					free_consultation(t_freemoi *eldoctor);
void					exit_custum(char *error, int type);
void					print_arb(t_tree *st, char flags);
void					init_state_ls(t_state_ls *ls);
// void					good_end(t_freemoi *eldoctor);
void					print_l_mode(t_file *data);
void					free_parms(char **parms);
void					free_tree(t_tree *tree);
void					free_data(t_file *data);
t_freemoi				*free_patient(t_freemoi * eldoctor);
char					**cpy_parms(const char **argv, int argc, int i, t_freemoi *eldoctor);
t_file					*create_data_file(char *dir_file, t_freemoi *eldoctor);
t_freemoi				*add_patient(t_freemoi *eldoctor,
							void **patient, int patho);
#endif
