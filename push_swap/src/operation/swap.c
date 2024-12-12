/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:55:24 by nacao             #+#    #+#             */
/*   Updated: 2024/12/02 12:09:19 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*seconde;
	t_stack_node	*third;

	if (!*head || (*head)->next == NULL)
		return ;
	first = *head;
	seconde = first->next;
	third = seconde->next;
	first->next = seconde->next;
	if (third)
		third->prev = first;   
	first->prev = seconde;
	seconde->next= first;
	seconde->prev = NULL;
	*head = seconde;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}