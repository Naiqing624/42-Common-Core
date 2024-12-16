/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:37:25 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 15:11:40 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

//为每个字节里面的数字标上序列号
//并标记在中位数上 或者中位数下
void	current_index(t_stack_node *stack)
{
	int	median_len;
	int	i;

	if (!stack)
		return ;
	median_len = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median_len)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

//为stack a 找到 b 的目标节点（差值最小）
//如果没有找到 则选择 b 的最大点
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*target_node;
	t_stack_node	*current_b;

	while (a)
	{
		best_match = LONG_MIN;
		target_node = NULL;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

//计算每个节点的pushcost
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

//找到整个stack中 pushcost的值最小的node
//然后把这个node->cheapest设置为true
void	set_cheapest(t_stack_node *stack)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (cheapest > stack->push_cost)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	set_value_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
