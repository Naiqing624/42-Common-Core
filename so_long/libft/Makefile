# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nacao <nacao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 10:15:15 by nacao             #+#    #+#              #
#    Updated: 2024/12/16 10:56:19 by nacao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

INC = inc/

LIBFT_DIR = libft/

FT_PRINTF_DIR = ft_printf/

SRCS = $(LIBFT_DIR)ft_isalpha.c \
		$(LIBFT_DIR)ft_isdigit.c \
		$(LIBFT_DIR)ft_isalnum.c \
		$(LIBFT_DIR)ft_isascii.c \
		$(LIBFT_DIR)ft_isprint.c \
		$(LIBFT_DIR)ft_strlen.c \
		$(LIBFT_DIR)ft_memset.c \
		$(LIBFT_DIR)ft_bzero.c \
		$(LIBFT_DIR)ft_memcpy.c \
    	$(LIBFT_DIR)ft_memmove.c \
		$(LIBFT_DIR)ft_strlcpy.c \
		$(LIBFT_DIR)ft_strlcat.c \
		$(LIBFT_DIR)ft_toupper.c \
		$(LIBFT_DIR)ft_tolower.c \
		$(LIBFT_DIR)ft_strchr.c \
		$(LIBFT_DIR)ft_strrchr.c \
		$(LIBFT_DIR)ft_putchar_fd.c \
		$(LIBFT_DIR)ft_atoi.c \
		$(LIBFT_DIR)ft_calloc.c \
		$(LIBFT_DIR)ft_itoa.c \
		$(LIBFT_DIR)ft_memcmp.c \
		$(LIBFT_DIR)ft_putendl_fd.c \
		$(LIBFT_DIR)ft_putnbr_fd.c \
		$(LIBFT_DIR)ft_putstr_fd.c \
		$(LIBFT_DIR)ft_split.c \
		$(LIBFT_DIR)ft_strdup.c \
		$(LIBFT_DIR)ft_memchr.c \
		$(LIBFT_DIR)ft_striteri.c \
		$(LIBFT_DIR)ft_strjoin.c \
		$(LIBFT_DIR)ft_strmapi.c \
		$(LIBFT_DIR)ft_strncmp.c \
		$(LIBFT_DIR)ft_strtrim.c \
		$(LIBFT_DIR)ft_substr.c \
		$(LIBFT_DIR)ft_strnstr.c \
		$(FT_PRINTF_DIR)ft_printf.c \
		$(FT_PRINTF_DIR)ft_printf_utils.c \
		$(FT_PRINTF_DIR)ft_printf_unsigned.c \
		$(FT_PRINTF_DIR)ft_itoa.c \
		$(FT_PRINTF_DIR)ft_printf_p.c \
		$(FT_PRINTF_DIR)ft_printf_x.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re