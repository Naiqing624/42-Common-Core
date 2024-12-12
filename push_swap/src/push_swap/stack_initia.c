/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:35:24 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 10:35:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

static void add_node(t_stack_node **stack, int n)
{
	t_stack_node	*tmp;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	tmp = malloc(sizeof(t_stack_node));
	if (!tmp)
		return ;
	tmp->nbr = n;
	tmp->next = NULL;
	tmp->cheapest = 0;
	if (*stack)
	{
		last_node = last_stack(stack);
		last_node->next = tmp;
		tmp->prev = last_node;
	}
	else
	{
		*stack = tmp;
		tmp->prev = NULL;
	}
}

//在把argv的值给到a之前 需要确认 数值是否正确（大小，符号，是否重复）
//把argv的数值给atol了
//然后再把argv的值给a
void	stack_a_initia(t_stack_node **a, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (is_syntax(argv[i]))
			error_free(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a);
		if (error_dup(*a, (int)n))
			error_free(a);
		add_node(a, (int)n);
		i++;
	}
}