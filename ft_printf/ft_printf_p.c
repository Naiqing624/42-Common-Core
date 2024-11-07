/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:22:24 by nacao             #+#    #+#             */
/*   Updated: 2024/11/07 17:22:28 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_countpointer(unsigned long long ptr)
{
    int count;

    count = 0;
    while (ptr != 0)
    {
        count++;
        ptr /= 16;
    }
    return (count);
}

int ft_printpointer(unsigned long long ptr)
{
    if (ptr >= 16)
    {
        ft_countpointer(ptr / 16);
        ft_countpointer(ptr % 16);
    }
    else
    {
        if (ptr > 9)
            ft_putchar(ptr + 'a');
        else
            ft_putchar(ptr);
    }
    return (ft_countpointer(ptr));
}

int ft_putpointer(unsigned long long ptr)
{
    int len;

    len = 0;
    if (ptr == 0)
    {
        len += write(1, "null", 4);
        return (len);
    }
    len = write (1, "0x", 2);
    len += ft_printpointer(ptr);
    return (len);
}