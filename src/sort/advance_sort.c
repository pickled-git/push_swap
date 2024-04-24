/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:08:59 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/24 22:56:42 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		pb(a, b);
		count++;
	}
	if (is_sorted(*b))
		rb(b);
}

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

t_stack	*find_elem(t_stack *a, t_stack *b)
{
	t_stack	*min_cost_elem;
	t_stack	*current;
	int		min_cost;
	int		cost;

	min_cost_elem = NULL;
	min_cost = INT_MAX;
	current = a;
	while (current)
	{
		cost = calculate_cost(a, b, current->value);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_elem = current;
		}
		current = current->next;
	}
	return (min_cost_elem);
}

void	perform_rotations(t_stack **stack, int pos)
{
	int	size;
	int	forward_rotations;
	int	reverse_rotations;

	size = stack_size(*stack);
	forward_rotations = pos;
	reverse_rotations = size - pos;
	if (forward_rotations <= reverse_rotations)
	{
		for (int i = 0; i < forward_rotations; i++)
			ra(stack);
	}
	else
	{
		for (int i = 0; i < reverse_rotations; i++)
			rra(stack);
	}
}

void	advance_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;
	int		pos_in_a;
	int		pos_in_b;

	push_to_b(a, b);
	while (*a)
	{
		min_cost = find_elem(*a, *b);
		pos_in_a = find_index(*a, min_cost->value);
		perform_rotations(a, pos_in_a);
		pos_in_b = find_position(*b, min_cost->value);
		perform_rotations(b, pos_in_b);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
    rotate_to_min(a);
}
