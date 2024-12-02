/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:11:47 by nacao             #+#    #+#             */
/*   Updated: 2024/12/02 13:22:42 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void re_rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;

    last_node = last_stack(*stack);
    (*stack)->prev = last_node;
}