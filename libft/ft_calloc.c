/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:33:45 by nacao             #+#    #+#             */
/*   Updated: 2024/10/23 08:19:30 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	if (count != 0 && total_size / count != size)
	{
		return (NULL);
	}
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
int main()
{
    int *arr;
    size_t n = 5;

    arr = (int *)ft_calloc(n, sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Array elements after ft_calloc initialization:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}*/
