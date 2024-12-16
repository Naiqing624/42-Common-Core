/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:04 by nacao             #+#    #+#             */
/*   Updated: 2024/12/12 16:40:56 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

//handle errors
int				is_syntax(char *str);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack);

//Stack initiation
void			stack_a_initia(t_stack_node **a, char **argv);

//nodes initiation

//Stack utils
int				stack_len(t_stack_node *stack);
t_stack_node	*last_stack(t_stack_node *stack);
char			**ft_ssplit(char *str, char c);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

//Commands
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			sort_three(t_stack_node **stack);
void			sort_stack(t_stack_node **a, t_stack_node **b);

//Algorhithms
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			set_value_a(t_stack_node *a, t_stack_node *b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			set_value_b(t_stack_node *a, t_stack_node *b);
void			before_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);

#endif