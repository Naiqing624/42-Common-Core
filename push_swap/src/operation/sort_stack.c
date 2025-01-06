/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:01 by nacao             #+#    #+#             */
/*   Updated: 2024/12/18 13:53:40 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		set_value_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_value_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

// void	sort_stack(t_stack_node **a, t_stack_node **b)
// {
// 	int	len_a;

// 	len_a = stack_len(*a);
// 	printf("Initial length of stack A: %d\n", len_a);
// 	print_stack(*a, "Stack A (initial)");
// 	print_stack(*b, "Stack B (initial)");

// 	// 将节点推入栈 B，直到栈 A 剩下 3 个节点
// 	while (len_a-- > 3 && !stack_sorted(*a))
// 	{
// 		printf("\nExecuting pb (remaining length of A: %d):\n", len_a);
// 		printf("\nCalling pb:\n");
// 		printf("Pointer A (before pb): %p\n", (void *)a);
// 		printf("Pointer B (before pb): %p\n", (void *)b);
// 		pb(b, a, false);
// 		print_stack(*a, "Stack A after pb");
// 		print_stack(*b, "Stack B after pb");
// 	}

// 	// 处理栈 A 中剩余的节点
// 	while (len_a-- > 3 && !stack_sorted(*a))
// 	{
// 		printf("\nSetting values for A and B...\n");
// 		set_value_a(*a, *b); // 为节点设置数值，例如目标节点
// 		print_stack(*a, "Stack A before move_a_to_b");
// 		print_stack(*b, "Stack B before move_a_to_b");

// 		move_a_to_b(a, b);
// 		print_stack(*a, "Stack A after move_a_to_b");
// 		print_stack(*b, "Stack B after move_a_to_b");
// 	}

// 	// 对剩余的 3 个节点排序
// 	printf("\nSorting last three nodes in stack A...\n");
// 	sort_three(a);
// 	print_stack(*a, "Stack A after sort_three");

// 	// 将栈 B 中的节点推回栈 A
// 	while (*b)
// 	{
// 		printf("\nSetting values for B and moving nodes back to A...\n");
// 		set_value_b(*a, *b);
// 		print_stack(*a, "Stack A before move_b_to_a");
// 		print_stack(*b, "Stack B before move_b_to_a");

// 		move_b_to_a(a, b);
// 		print_stack(*a, "Stack A after move_b_to_a");
// 		print_stack(*b, "Stack B after move_b_to_a");
// 	}

// 	// 调整栈 A，确保最小值在顶部
// 	printf("\nFinal adjustment of stack A...\n");
// 	current_index(*a);
// 	min_on_top(a);
// 	print_stack(*a, "Final sorted Stack A");
// }
