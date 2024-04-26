/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:08:59 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/26 19:51:20 by oprosvir         ###   ########.fr       */
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

void	single_stack_rotations(t_stack **stack, int rotations, bool is_forward,
		bool is_stack_a)
{
	while (rotations > 0)
	{
		if (is_forward)
		{
			if (is_stack_a)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (is_stack_a)
				rra(stack);
			else
				rrb(stack);
		}
		rotations--;
	}
}

void	perform_rotations(t_stack **stack_a, int a_cost, t_stack **stack_b,
		int b_cost)
{
	if (a_cost > 0 && b_cost > 0)
	{
		while (a_cost > 0 && b_cost > 0)
		{
			rr(stack_a, stack_b);
			a_cost--;
			b_cost--;
		}
	}
	else if (a_cost < 0 && b_cost < 0)
	{
		while (a_cost < 0 && b_cost < 0)
		{
			rrr(stack_a, stack_b);
			a_cost++;
			b_cost++;
		}
	}
	single_stack_rotations(stack_a, ft_abs(a_cost), (a_cost >= 0), true);
	single_stack_rotations(stack_b, ft_abs(b_cost), (b_cost >= 0), false);
}

void	advance_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;
	int		pos_in_a;
	int		pos_in_b;
	int		a_cost;
	int		b_cost;

	push_to_b(a, b);
	while (*a)
	{
		min_cost = find_elem(*a, *b);
		pos_in_a = find_index(*a, min_cost->value);
		pos_in_b = find_position(*b, min_cost->value);
		a_cost = rotation_cost(stack_size(*a), pos_in_a);
		b_cost = rotation_cost(stack_size(*b), pos_in_b);
		perform_rotations(a, a_cost, b, b_cost);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	rotate_to_min(a);
}
