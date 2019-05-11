# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 17:05:30 by jhamon            #+#    #+#              #
#    Updated: 2019/05/07 18:19:39 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

AUTEUR = "jhamon"

CC = gcc

# FLAG = -Wall -Werror -Wextra

#path
INC = -I ./includes/
SRC_PATH = src/
OBJ_PATH  = obj/

#srcs
SRC_PS = main.c ft_parse_option.c ft_recursive_while.c ft_fild_tree.c

SRC = $(addprefix $(SRC_PATH), $(SRC_PS))
OBJ = $(addprefix $(OBJ_PATH), $(SRC_PS:.c=.o))

LIB = -L libft/ -lft

# Utile
_END=tput sgr0
_BOLD=tput bold
_UNDER=tput smul
_REV=tput smso
_DAFUK=tput smacs

# Colors
_GREY=tput setaf 250
_RED=tput setaf 160
_GREEN=tput setaf 10
_YELLOW=tput setaf 11
_BLUE=tput setaf 27
_PURPLE=tput setaf 92
_CYAN=tput setaf 50
_WHITE=tput setaf 255

# Inverted
_IGREY=tput setab 250
_IRED=tput setab 160
_IGREEN=tput setab 10
_IYELLOW=tput setab 11
_IBLUE=tput setab 27
_IPURPLE=tput setab 92
_ICYAN=tput setab 50
_IWHITE=tput setab 255

define OK
	@$(call _GREEN) && printf "[Ok]	"
	@$(call _UNDER)
	@$(call _YELLOW) && printf "$1\n"
	@$(call _END)
endef

define FOK
	@$(call _GREEN) && printf "\n[Compiled]	"
	@$(call _CYAN) && printf "$1\n"
	@$(call _END)
endef

define CLNOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "$1\n"
	@$(call _END)
endef

define CLNOBJOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "Obj_$(NAME)\n"
	@$(call _END)
endef

define BULSHIT
	@$(call _PURPLE) && printf "auteur :	"
	@$(call _RED) && printf "$(AUTEUR)\n"
	@$(call _END)
endef

all : $(NAME)
	@make -C libft
	@:

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) -o $@ $(SRC) $(INC) $(LIB) $(FLAG)
	@make auteur
	$(call FOK,$@)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p `dirname $@`
ifeq ($(DB),1)
	@$(CC) -c $(G3) $(INC) $< -o $@
else
	@$(CC) -c $(FLAGS) $(INC) $< -o $@
endif
	$(call OK,$*)

clean :
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	$(call CLNOBJOK,$(OBJ))

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)
	$(call CLNOK,$(NAME))

re : fclean all

debug :
	@make DB=1
	@make -C libft DB=1

auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

norme :
	@make -C libft norme
	@norminette $(SRC)

.PHONY : all clean fclean re debug auteur
