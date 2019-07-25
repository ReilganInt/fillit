# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmormont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 19:51:24 by vmormont          #+#    #+#              #
#    Updated: 2019/06/08 22:00:49 by vmormont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= fillit 

SRC_DIR:= ./src
INC_DIR:= ./includes
OBJ_DIR:= ./obj
LIB_DIR:= ./libft

SRC:= main.c \
	additional.c \
	get_tetri.c \
	position.c \
	solver.c \
	validation.c

OBJ:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC:= gcc
CFLAGS:= -Wall -Wextra -Werror

.PHONY: all dir clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(LIB_DIR)/includes -I $(INC_DIR) -o $@ -c $<

$(NAME): dir $(OBJ)
	$(CC) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)

dir:
	mkdir -p $(OBJ_DIR)
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: fclean all
