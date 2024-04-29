/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:14:51 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/29 18:41:50 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a = init_stack(argc, argv);
	if (stack_a && !is_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(stack_a);
	return (0);
}
