# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmormont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 19:46:04 by vmormont          #+#    #+#              #
#    Updated: 2019/05/06 06:06:37 by vmormont         ###   ########.fr        #
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

all:
		mkdir -p $(OBJ_DIR)
		@$(MAKE) -C $(L_FT) --no-print-directory
		@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -I $(L_FT)/includes -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
		$(CC) $(OBJ) -L $(L_FT) -l ft -o $(NAME)

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re:
		@$(MAKE) fclean --no-print-directory
		@$(MAKE) all --no-print-directory

relibs:
		@$(MAKE) -C $(L_FT) re --no-print-directory
		@$(MAKE) re --no-print-directory
