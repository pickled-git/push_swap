/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:53:28 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/24 20:57:44 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	find_position(t_stack *b, int value)
{
	t_stack	*tmp;
	int		pos;

	if (value > b->value && value < stack_get_last(b)->value)
		pos = 0;
	else if (value > max_value(b) || value < min_value(b))
		pos = find_index(b, max_value(b));
	else
	{
		pos = 1;
		tmp = b->next;
		while (b->value < value || tmp->value > value)
		{
			b = b->next;
			tmp = b->next;
			pos++;
		}
	}
	return (pos);
}

static int	rotation_cost(int size, int pos)
{
	int	forward;
	int	reverse;

	forward = pos;
	reverse = size - pos;
	if (forward < reverse)
		return (forward);
	else
		return (reverse);
}

int	calculate_cost(t_stack *a, t_stack *b, int value)
{
	int b_pos;
	int b_rotations;
	int a_index;
	int a_rotations;

	b_pos = find_position(b, value);
	b_rotations = rotation_cost(stack_size(b), b_pos);
	a_index = find_index(a, value);
	a_rotations = rotation_cost(stack_size(a), a_index);
	return (a_rotations + b_rotations);
}