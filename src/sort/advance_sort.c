/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:08:59 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/25 21:38:04 by oprosvir         ###   ########.fr       */
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

void	perform_rotations(t_stack **stack, int pos, bool is_stack_a)
{
	int	size;
	int	forward_rotations;
	int	reverse_rotations;

	size = stack_size(*stack);
	forward_rotations = pos;
	reverse_rotations = size - pos;
	if (forward_rotations <= reverse_rotations)
		rotate_stack(stack, forward_rotations, is_stack_a);
	else
		reverse_stack(stack, reverse_rotations, is_stack_a);
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
		perform_rotations(a, pos_in_a, true);
		pos_in_b = find_position(*b, min_cost->value);
		perform_rotations(b, pos_in_b, false);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	rotate_to_min(a);
}
