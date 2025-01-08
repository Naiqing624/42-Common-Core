# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nacao <nacao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 18:19:23 by nacao             #+#    #+#              #
#    Updated: 2025/01/08 18:19:23 by nacao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = so_long

GREEN           = \033[0;32m
RED             = \033[0;31m
RESET           = \033[0m

LIBFT           = ./libft/lib/libft.a

CC              = clang

CFLAGS          = -Wall -Werror -Wextra -I./libft/minilibx-linux
LDFLAGS         = -L./libft/minilibx-linux -lmlx -lXext -lX11

VALGRIND        = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE          = rm -f

SRC_DIR        = ./src/

SRCS = $(SRC_DIR)check_argc.c \
		$(SRC_DIR)check_map.c \
		$(SRC_DIR)error_free.c \
		$(SRC_DIR)handle_input.c \
		$(SRC_DIR)initia_game.c \
		$(SRC_DIR)initia_map.c \
		$(SRC_DIR)quit_game.c \
		$(SRC_DIR)rendre_map.c \
		$(SRC_DIR)so_long.c

all:            ${LIBFT} ${NAME}

${NAME}:        
		${CC} ${SRCS} ${LIBFT} ${CFLAGS} ${LDFLAGS} -o ${NAME}
		@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
		@echo

${LIBFT}:
		@echo
		make bonus -C libft/lib

clean:
		make clean -C libft/lib
		@echo

fclean:
		${REMOVE} ${NAME}
                @echo "${NAME}: ${RED}${NAME} were deleted${RESET}"
		@echo

re:             fclean all

run:            ${NAME}
		${VALGRIND} ./${NAME} assets/map/map1.ber

.PHONY:         all clean fclean re rebonus valgrind run run_bonus

