/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:14:51 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 23:09:06 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack *stack_a;

	stack_a = init_stack(argc, argv);
	if (!is_sorted(stack_a))
	{
		printf("Stack A:\n");
		print_stack(stack_a);
	}
	free_stack(stack_a);
	return (0);
}