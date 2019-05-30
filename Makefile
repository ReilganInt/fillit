# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmormont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 19:46:04 by vmormont          #+#    #+#              #
#    Updated: 2019/05/30 10:02:15 by vmormont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit 

SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./lib

SRC		:= main.c \
			reader.c \
			solver.c
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

L_FT	:= $(LIB_DIR)/libft

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -I $(L_FT)/includes -I $(INC_DIR) -o $@ -c $<

$(NAME): dir $(OBJ)
		$(CC) $(OBJ) -L $(L_FT) -l ft -o $(NAME)

dir:
		mkdir -p $(OBJ_DIR)
		make -C $(L_FT)

clean:
		rm -rf $(OBJ_DIR)
		make -C $(L_FT) clean

fclean: clean
		make -C $(L_FT) fclean
		rm -rf $(NAME)

re: fclean all
