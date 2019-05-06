/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:47:47 by jhamon            #+#    #+#             */
/*   Updated: 2019/04/26 16:18:05 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define CH(X) printf("%50c-- check %d --\n", ' ', X);
# define A 2
# define L 4
# define T 1
# define R 16
# define MR 8


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include "libft.h"

typedef struct       s_file {
  char*              dir;
  char*              name;
  char*              user_name;
  char*              last_state;
  char*              last_modif;
  char*              last_access;
  char*              user_passwd;
  char*              user_real_name;
  char*              permissions_type;
  long int           time;
  long int           uid;
  long int           gid;
  long int           user_id;
  long int           file_size;
  long int           block_size;
  long int           num_inoeud;
  long int           link_number;
  long int           user_group_id;
  unsigned long int  st_mode;
  long long int      block_alloc;
}                    t_file;

typedef struct       s_bin_tree {
  struct s_bin_tree  *left;
  struct s_bin_tree  *right;
  t_file             *data;
}                    t_bin_tree;

/*
**  flag encode in a char:
**           -r  -R -l -a -t
** [0][0][0][1] [1][1][1][1]
*/
typedef struct        s_state_ls {
  unsigned char       match_flag[127];
  char                flags;
}                     t_state_ls;

void            parse_option(const char* flags, t_state_ls *ls);
void            recursive_while(t_state_ls *ls, int iterate, char **dir_files);
void            fild_tree(t_bin_tree tree, char **dir_files, char flags);
#endif
