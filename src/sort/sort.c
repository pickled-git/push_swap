/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:11 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/24 22:28:07 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < third && second > third)
	{
		sa(a);
		ra(a);
	}
}

int	find_min_index(t_stack *a)
{
	int		min_index;
	int		index;
	int		min_value;
	t_stack	*current;

	min_index = 0;
	index = 0;
	min_value = a->value;
	current = a;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	if (min_index <= stack_size(*a) / 2)
	{
		while (min_index--)
			ra(a);
	}
	else
	{
		while (min_index++ < stack_size(*a))
			rra(a);
	}
	pb(a, b);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		push_min_to_b(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack *stack_b;
	int size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size <= 5)
		simple_sort(stack_a, &stack_b);
	else
		advance_sort(stack_a, &stack_b);
	free_stack(stack_b);
}