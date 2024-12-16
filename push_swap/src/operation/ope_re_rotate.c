/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_re_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:11:47 by nacao             #+#    #+#             */
/*   Updated: 2024/12/16 16:09:45 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	re_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*prev;

	if (!*stack || (*stack)->next)
		return ;
	last = last_stack(*stack);
    prev = last->prev;
    if (prev)
        prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
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
