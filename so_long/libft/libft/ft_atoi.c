/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:36:17 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 11:17:52 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
int main(void)
{
    const char *test1 = "42";
    const char *test2 = "-42";
    const char *test3 = "    1234";
    const char *test4 = "+5678";
    const char *test5 = "  -9876xyz";
    const char *test6 = "0";
    const char *test7 = "  \t\n\r\v\f2147483647";  // INT_MAX
    const char *test8 = "  -2147483648";          // INT_MIN
    const char *test9 = "9999999999999999999999999"; 

    printf("ft_atoi(\"%s\") = %d\n", test1, ft_atoi(test1));
    printf("ft_atoi(\"%s\") = %d\n", test2, ft_atoi(test2));
    printf("ft_atoi(\"%s\") = %d\n", test3, ft_atoi(test3));
    printf("ft_atoi(\"%s\") = %d\n", test4, ft_atoi(test4));
    printf("ft_atoi(\"%s\") = %d\n", test5, ft_atoi(test5));
    printf("ft_atoi(\"%s\") = %d\n", test6, ft_atoi(test6));
    printf("ft_atoi(\"%s\") = %d\n", test7, ft_atoi(test7));
    printf("ft_atoi(\"%s\") = %d\n", test8, ft_atoi(test8));
    printf("ft_atoi(\"%s\") = %d\n", test9, ft_atoi(test9));

    return 0;
}*/
