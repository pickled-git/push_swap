/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:20:46 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/19 12:41:13 by oprosvir         ###   ########.fr       */
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

int	find_max_index(t_stack *stack)
{
	int		max_index;
	t_stack	*current;

	max_index = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}
