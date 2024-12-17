/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:01 by nacao             #+#    #+#             */
/*   Updated: 2024/12/16 16:18:36 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a,
							t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
									t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	//printf("cheapest_node: %p\n", (void *)cheapest_node);
	if (cheapest_node)
   	 //printf("cheapest_node->target_node: %p\n", (void *)cheapest_node->target_node);
	if (cheapest_node && cheapest_node->target_node)
	{
   		if (cheapest_node->target_node->above_median)
    	{
			if (cheapest_node->above_median
				&& cheapest_node->target_node->above_median)
				rotate_both(a, b, cheapest_node);
			else if (!(cheapest_node->above_median)
				&& !(cheapest_node->target_node->above_median))
				rev_rotate_both(a, b, cheapest_node);
    	}
	}
	// else
	// {
    // 	printf("Error: NULL pointer detected in move_a_to_b\n");
    // 	exit(1);
	// }
	before_push(a, cheapest_node, 'a');
	before_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	before_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, false); 
}

static void	min_on_top(t_stack_node **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; //To store the length of stack `a`

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		set_value_a(*a, *b); //Iniate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	sort_three(a);
	while (*b) //Until the end of stack `b` is reached
	{
		set_value_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*a); //Refresh the current position of stack `a`
	min_on_top(a); //Ensure smallest number is on top
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
