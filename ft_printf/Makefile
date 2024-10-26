# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nacao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 10:15:15 by nacao             #+#    #+#              #
#    Updated: 2024/10/25 09:41:37 by nacao            ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft -fPIC

NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_ptr.c ft_printf_unsigned.c ft_printf_hex.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME) so

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) .

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS) $(LIBFT)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME) libft.a libftprintf.so *.so
	make fclean -C $(LIBFT_DIR)

re: fclean all

so: $(LIBFT) $(OBJS)
	$(CC) -shared -o libftprintf.so $(OBJS) $(LIBFT)