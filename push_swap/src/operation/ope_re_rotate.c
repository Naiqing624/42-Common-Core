/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:11:47 by nacao             #+#    #+#             */
/*   Updated: 2024/12/05 14:02:54 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	re_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || (*stack)->next)
		return;
	last_node = last_stack(*stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	re_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	re_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	re_rotate(a);
	re_rotate(b);
	if (print)
		ft_printf("rrr\n");
}