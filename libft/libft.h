/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:27:33 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 19:02:40 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>
# include <inttypes.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <stddef.h>
# include <stdint.h>

# define RED	"\033[1;31m"
# define BLACK	"\033[1;30m"
# define BLUE	"\033[1;34m"
# define GREEN	"\033[1;32m"
# define GREY	"\033[1;37m"
# define YELLOW	"\033[1;33m"
# define PURPLE	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define EOC	"\033[0;m"
# define BUFF_SIZE 100

/*
**structure pour ft_printf
*/
typedef	struct	s_list
{
	char		buff[BUFF_SIZE];
	int			curs;
	int			zero;
	int			moin;
	int			plus;
	int			esp;
	int			htag;
	int			l;
	int			h;
	int			lm;
	int			j;
	int			z;
	int			champ;
	int			precision;
	int			rtrn;
}				t_list;

/*
**fonction ft_printf
*/
int				ft_printf(const char *format, ...);
int				ft_strlen_ptf(char const *str);
void			ft_recup_char(t_list *var, va_list ap, unsigned char *buf);
int				ft_color(const char *format, t_list *var);
void			ft_printparms(const char *tmp, int *i, t_list *var, va_list ap);
int				ft_care_is_me(const char *tmp, t_list *var, va_list ap);
void			ft_offplace(char tmp, t_list *var);
int				ft_compt(long long nbr, int base);
void			ft_resetprset(t_list *var);
long long		ft_atoi_ptf(const char *str);
void			ft_itoab_buff(long long nbr, int base, t_list *var);
int				ft_charcmp(int c, char const *s1);
int				ft_charnumb(char const *s1, int c);
int				ft_copyinbuff(char c, t_list *var);
void			ft_strupper(char *tmp);
void			ft_regulflag(t_list *var);
void			ft_printf_b(t_list *var, int i, va_list ap);
void			ft_printf_c(t_list *var, int i, void *item);
void			ft_printf_cc(t_list *var, int i, void *item);
void			ft_printf_x(t_list *var, int i, void *item, int n);
void			ft_printf_s(t_list *var, int i, void *item);
void			ft_printf_ss(t_list *var, int i, void *item);
void			ft_printf_p(t_list *var, int i, void *item);
void			ft_printf_u(t_list *var, int i, void *item);
void			ft_printf_i(t_list *var, int i, void *item);
void			ft_printf_o(t_list *var, int i, void *item);
void			ft_printf_pc(t_list *var, int i);
void			ft_lstinitcurs(t_list *li);
void			ft_lstinit(t_list *li);
void			ft_put_wc(int32_t c, t_list *var);
int				ft_ucompt(unsigned long long nbr, int base);
void			ft_copystr(t_list *var, char *str);
int				ft_memdel_zero(void **ap);

/*
**fonction lib et gnl
*/
unsigned long	ft_strlcat(char *str, const char *strc, unsigned long n);
size_t			ft_strlen(char const *str);
void			*ft_memccpy(void *str, const void *strc, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *str, int a, size_t len);
void			*ft_memcpy(void *str, const void *strc, size_t n);
void			*ft_memmove(void *str, const void *strc, size_t n);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int nbr, int fd);
void			ft_putchar(char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_memdel(void **ap);
char			**ft_strsplit(char const *s, char c);
char			*ft_strdup(char const *s1);
char			*ft_strcat(char *str, const char *strc);
char			*ft_strncat(char *str, const char *strc, size_t n);
char			*ft_strstr(const char *str, const char *chrch);
char			*ft_strnstr(const char *str, const char *chrch, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strcpy(char *str, const char *strc);
char			*ft_strncpy(char *str, const char *strc, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
int				get_next_line(const int fd, char **line);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

#endif
