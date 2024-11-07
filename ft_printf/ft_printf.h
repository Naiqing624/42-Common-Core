/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:55:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/03 14:55:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

//ft_printf.c
int ft_printf(const char *format, ...);

//ft_printf_utils.c
int ft_putchar(char i);
int	ft_putstr(char *str);
int	ft_putnum(int n);
int	ft_strlen(const char *str);

//ft_printf_unsigned.c
int get_size(unsigned int n);
char *ft_utoa(unsigned int n);
int	ft_putunsigned(unsigned int n);

//ft_itoa.c
char	*ft_itoa(int n);

//ft_printf_p.c
static int ft_countpointer(unsigned long long ptr);
int ft_printpointer(unsigned long long ptr);
int ft_putpointer(unsigned long long ptr);

#endif