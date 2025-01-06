/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_move_a_to_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:53:12 by nacao             #+#    #+#             */
/*   Updated: 2024/12/18 13:55:04 by nacao            ###   ########.fr       */
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
	before_push(a, cheapest_node, 'a');
	before_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}
