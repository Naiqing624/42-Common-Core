/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:04:20 by marvin            #+#    #+#             */
/*   Updated: 2024/12/01 18:04:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (*dst)
	{
		tmp->next = *dst;
		tmp->next->prev = NULL;
		*dst = tmp;
	}
	else
	{
		*dst = tmp;
		tmp->next = NULL; 
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}
