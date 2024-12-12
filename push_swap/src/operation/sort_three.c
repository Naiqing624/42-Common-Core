/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:27:27 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 21:27:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*max;

	max = find_max(*stack);
	if (max  ==  *stack)
		ra(stack, true);
	else if (max == (*stack)->next)
		rra(stack, true);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, true);
}