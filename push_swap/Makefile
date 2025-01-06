# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nacao <nacao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:00:10 by nacao             #+#    #+#              #
#    Updated: 2024/12/18 13:54:31 by nacao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = push_swap

LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)

# Source and Object files
SRCS = $(SRC_DIR)operation/push.c \
		$(SRC_DIR)operation/re_rotate.c \
		$(SRC_DIR)operation/rotate.c \
		$(SRC_DIR)operation/swap.c \
		$(SRC_DIR)operation/sort_stack.c \
		$(SRC_DIR)operation/sort_three.c \
		$(SRC_DIR)operation/sort_stack_move_a_to_b.c \
		$(SRC_DIR)push_swap/handle_error.c \
		$(SRC_DIR)push_swap/push_swap.c \
		$(SRC_DIR)push_swap/set_value_a.c \
		$(SRC_DIR)push_swap/set_value_b.c \
		$(SRC_DIR)push_swap/split.c \
		$(SRC_DIR)push_swap/stack_initia.c \
		$(SRC_DIR)push_swap/stack_utils.c

OBJ = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Targets
all: $(NAME)
	@echo "Build completed: $(NAME)"

$(LIBFT):
	@echo "Building Libft"
	@make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Object files compilation
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@echo "Cleaning binary files..."
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re