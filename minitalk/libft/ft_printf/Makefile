# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nacao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:50:23 by nacao             #+#    #+#              #
#    Updated: 2024/11/07 15:50:26 by nacao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CC =		cc

CFLAGES =	-Wall -Wextra -Werror

SRCS =		ft_printf.c ft_printf_utils.c ft_printf_unsigned.c ft_itoa.c ft_printf_p.c ft_printf_x.c

OBJS =		$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re