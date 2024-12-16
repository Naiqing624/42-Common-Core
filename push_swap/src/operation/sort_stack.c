/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:01 by nacao             #+#    #+#             */
/*   Updated: 2024/12/16 14:27:08 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

static void	min_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a > 3 && !(stack_sorted(*a)))
	{
        pb(a, b, true);
        len_a--;
        printf("len_a after pb: %d\n", len_a);
    }
	if (len_a-- > 3 && !(stack_sorted(*a)))
		pb(b, a, true);
	while (len_a-- > 3 && !(stack_sorted(*a)))
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
	min_top(a);
}
