/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:35:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 13:38:36 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

//必须得第一个对符号的检测 因为+和-都是可以的
//如果有符号 那第二个必须是数字
int	is_syntax(char *str)
{
	if (!str || !*str)
    	return (1);
	if (!(*str == '+' || *str == '-'
		|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

//stack 指向的内容会随着 current 的操作而改变
//指向的内容是共享的（链表节点在同一个内存区域中）
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_error_free(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}

int	ft_error_dup(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}