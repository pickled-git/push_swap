/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:20:46 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:47 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_stack **a)
{
	int	min_val;
	int	pos_in_a;
	int	size;

	min_val = min_value(*a);
	pos_in_a = find_index(*a, min_val);
	size = stack_size(*a);
	if (pos_in_a <= size / 2)
	{
		while ((*a)->value != min_val)
			ra(a);
	}
	else
	{
		while ((*a)->value != min_val)
			rra(a);
	}
}

int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack->value != value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	max_value(t_stack *stack)
{
	int	max;

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
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
