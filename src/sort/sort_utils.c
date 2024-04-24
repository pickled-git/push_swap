/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:20:46 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/24 19:43:31 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_position(t_stack *stack, int index)
{
	int		pos;
	t_stack	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	rotate_to_index(t_stack **stack, int index)
{
	while ((*stack)->index != 0)
	{
		if (find_index_position(*stack, index) <= stack_size(*stack) / 2)
			rb(stack);
		else
			rrb(stack);
	}
}

int	max_value(t_stack *stack)
{
	int		max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	min_value(t_stack *stack)
{
	int		min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	max_index(t_stack *stack)
{
	int		max_index;

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	min_index(t_stack *stack)
{
	int		min_index;

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}
