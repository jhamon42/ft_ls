# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 16:45:22 by jhamon            #+#    #+#              #
#    Updated: 2019/05/14 15:18:14 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
SRC = 	get_next_line.c	ft_memalloc.c 	ft_memdel.c 	ft_strnew.c 	ft_strdel.c \
		ft_strclr.c 	ft_striter.c 	ft_striteri.c 	ft_strmap.c 	ft_strmapi.c \
		ft_strequ.c 	ft_strnequ.c 	ft_strsub.c 	ft_strjoin.c 	ft_strtrim.c \
		ft_strsplit.c 	ft_itoa.c		ft_putchar.c 	ft_putstr.c 	ft_putendl.c \
		ft_putnbr.c 	ft_putchar_fd.c ft_putstr_fd.c 	ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi.c 		ft_isdigit.c 	ft_memcpy.c 	ft_strcmp.c 	ft_strncat.c \
		ft_strstr.c 	ft_bzero.c 		ft_isprint.c 	ft_memmove.c 	ft_strcpy.c \
		ft_strncmp.c 	ft_tolower.c 	ft_isalnum.c 	ft_memccpy.c 	ft_memset.c \
		ft_strdup.c 	ft_strncpy.c 	ft_toupper.c 	ft_isalpha.c 	ft_memchr.c \
		ft_strcat.c 	ft_strlcat.c 	ft_strnstr.c 	ft_isascii.c 	ft_memcmp.c \
		ft_strchr.c 	ft_strlen.c 	ft_strrchr.c 	ft_printf_s.c 	ft_memdel_zero.c\
		ft_printf_c.c 	ft_printf_ss.c 	ft_itoa_base.c 	ft_printf_cc.c 	ft_printf_u.c \
		ft_strlen_ptf.c	ft_atoi_ptf.c 	ft_printf_i.c 	ft_printf_x.c 	ft_care_is_me.c \
		ft_printf_o.c 	ft_printparms.c ft_strsub.c 	ft_charcmp.c 	ft_printf.c \
		ft_printf_p.c 	ft_put_wchar.c 	ft_strupper.c 	ft_charnumb.c 	ft_printf_pc.c \
		ft_resetprset.c	ft_color.c 		ft_printf_b.c 	ft_memdel_zero.c

define OK
	@tput setaf 254
	@echo -n $1
	@tput bold setaf 10
	@echo ' 	[Ok]'
	@tput sgr0
endef

define FOK
	@echo ''
	@tput setaf 50
	@echo -n $(NAME)
	@tput  bold setaf 10
	@echo ' [Compiled]'
	@tput sgr0
endef

all : $(NAME)
	@:

$(NAME) : $(OBJ)
	@$(CC) -c $(SRC) $(FLAG)
	@ar -rc $(NAME) $(OBJ)
ifndef SLEEP
	$(call FOK, $*)
endif

silence :
	@make SLEEP=1

force : $(OBJ)
	@$(CC) -c $(SRC)
	@ar -rc $(NAME) $(OBJ)
	$(call FOK, $*)

%.o: %.c
	@$(CC) -c $(FLAG) $< -o $@
ifndef SLEEP
	$(call OK, $*)
endif

clean :
	@rm -rf $(OBJ)
	@tput setaf 50
	@echo -n 'Obj'
	@tput setaf 10
	@echo ' 	clean success'
	@tput sgr0

fclean : clean
	@rm -rf $(NAME)
	@tput setaf 50
	@echo -n $(NAME)
	@tput setaf 10
	@echo ' clean success'
	@tput sgr0

re : fclean all

debug :
	@make DB=1
	@make -C libft DB=1

auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

norme :
	@norminette $(SRC)

.PHONY : all clean fclean re force norme auteur debug
