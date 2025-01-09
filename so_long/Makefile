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

SRC_DIR         = ./src/
OBJ_DIR         = ./obj/

SRCS            = check_argc.c check_map.c error_free.c handle_input.c \
                  initia_game.c initia_map.c quit_game.c rendre_map.c \
                  so_long.c
SRCS_FULL       = $(addprefix $(SRC_DIR), $(SRCS))
OBJS            = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all:            ${LIBFT} ${NAME}

${OBJ_DIR}:
		@mkdir -p ${OBJ_DIR}

${OBJS}: ${OBJ_DIR}%.o: ${SRC_DIR}%.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ_DIR} ${OBJS}
		${CC} ${OBJS} ${LIBFT} ${CFLAGS} ${LDFLAGS} -o ${NAME}
		@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
		@echo

${LIBFT}:
		@echo
		make bonus -C libft/lib

clean:
		make clean -C libft/lib
		${REMOVE} ${OBJS}
		@echo "$(NAME): $(RED)Object files were deleted$(RESET)"
		@echo

fclean: clean
		${REMOVE} ${NAME}
		@echo "$(NAME): $(RED)${NAME} was deleted$(RESET)"
		@echo

re:             fclean all

run:            ${NAME}
		${VALGRIND} ./${NAME} assets/map/map1.ber

.PHONY:         all clean fclean re rebonus valgrind run run_bonus

