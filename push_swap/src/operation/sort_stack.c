/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:01 by nacao             #+#    #+#             */
/*   Updated: 2024/12/12 16:55:53 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stack(t_stack_node *a, t_stack_node *b)
{
	int	len_a;

	len_a = stack_len(a);
	if (len_a-- > 3 && !(stack_sorted(a)))
		pb(a, b, true);
	if (len_a-- > 3 && !(stack_sorted(a)))
		pb(a, b, true);
	while (len_a-- > 3 && !(stack_sorted(a)))
	{
		set_value_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(&a);
	while (b)
	{
		
	}
}