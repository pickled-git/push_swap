/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:43:06 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 23:12:46 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0); // Not sorted
		stack = stack->next;
	}
	return (1); // Sorted
}

// Function to check for duplicates in the stack
int	check_for_duplicate(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1); // Duplicate found
		stack = stack->next;
	}
	return (0); // No duplicates
}

t_stack	*init_stack(int argc, char *argv[])
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;
	int		value;

	stack = NULL;
	i = argc - 1;
	if (argc < 2)
		exit(EXIT_FAILURE);
	while (i > 0)
	{
		value = ft_atoi(argv[i]);
		if (check_for_duplicate(stack, value))
			exit_error();
		new_node = ft_lstnew(value);
		if (!new_node)
			exit(EXIT_FAILURE);
		ft_lstadd_front(&stack, new_node);
		i--;
	}
	return (stack);
}
