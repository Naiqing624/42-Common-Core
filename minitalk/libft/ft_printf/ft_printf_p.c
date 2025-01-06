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

static int	ft_countpointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		count++;
		ptr = ptr / 16;
	}
	return (count);
}

int	ft_printpointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_printpointer(ptr / 16);
		ft_printpointer(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			ft_putchar((ptr - 10) + 'a');
		else if (ptr <= 9)
			ft_putchar(ptr + '0');
	}
	return (ft_countpointer(ptr));
}

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = write (1, "0x", 2);
	len += ft_printpointer(ptr);
	return (len);
}

/*
#include <stdio.h> // 用于标准 printf 比较输出

int main()
{
    int num = 42;
    int *ptr = &num;

    // 测试指针输出
    ft_putpointer((unsigned long long)ptr);
    write(1, "\n", 1);

    // 使用标准 printf 进行比较
    printf("Expected: %p\n", (void *)ptr);

    // 测试 NULL 指针
    ft_putpointer(0);
    write(1, "\n", 1);

    printf("Expected: (nil)\n");

    return 0;
}*/