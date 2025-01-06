/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:17:45 by nacao             #+#    #+#             */
/*   Updated: 2025/01/06 09:22:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	init_and_check(int argc, char ***argv, t_stack_node **a)
{
	char	**split_argv;

	split_argv = NULL;
	if (argc == 1 || (argc == 2 && !(*argv)[1][0]))
		print_error();
	else if (argc == 2)
	{
		split_argv = ft_ssplit((*argv)[1], ' ');
		*argv = split_argv;
	}
	stack_a_initia(a, (*argv) + 1);
	if (split_argv)
		free_argv(split_argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	init_and_check(argc, &argv, &a);
	if (stack_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (!(stack_sorted(a)))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
