# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nacao <nacao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:00:10 by nacao             #+#    #+#              #
#    Updated: 2024/12/16 13:07:53 by nacao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories
LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC)

# Source and Object files
SRCS = $(SRC_DIR)operation/move_a_to_b.c \
		$(SRC_DIR)operation/ope_push.c \
		$(SRC_DIR)operation/ope_re_rotate.c \
		$(SRC_DIR)operation/ope_rotate.c \
		$(SRC_DIR)operation/ope_swap.c \
		$(SRC_DIR)operation/set_value_a.c \
		$(SRC_DIR)operation/set_value_b.c \
		$(SRC_DIR)operation/sort_stack.c \
		$(SRC_DIR)operation/sort_three.c \
		$(SRC_DIR)push_swap/handle_error.c \
		$(SRC_DIR)push_swap/push_swap.c \
		$(SRC_DIR)push_swap/split.c \
		$(SRC_DIR)push_swap/stack_initia.c \
		$(SRC_DIR)push_swap/stack_utils.c

OBJ = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Targets
all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Object files compilation
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
