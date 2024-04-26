/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:20:46 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/26 17:26:59 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	rotation_cost(int size, int pos)
{
	int	forward;
	int	reverse;

	forward = pos;
	reverse = size - pos;
	if (forward <= reverse)
		return (forward);
	else
		return (-reverse);
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
