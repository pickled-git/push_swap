/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:08:59 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/24 21:15:34 by oprosvir         ###   ########.fr       */
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
	current = a;
	while (current)
	{
		cost = calculate_cost(a, b, current->value);
        printf("%d\n", cost); //отладка
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_elem = current;
		}
		current = current->next;
	}
	return (min_cost_elem);
}

/* TODO: fix func

void	perform_rotations(t_stack **a, t_stack *min_cost_elem) {
	int forward_rotations = 0;
	int reverse_rotations = 0;
	int index = 0;
	t_stack *current = *a;

	// Находим индекс min_cost_elem в стеке a
	while (current != NULL && current != min_cost_elem) {
		index++;
		current = current->next;
	}

	int size = stack_size(*a);
	forward_rotations = index;  // Прямые ротации до верха
	reverse_rotations = size - index;  // Обратные ротации до верха

	if (forward_rotations <= reverse_rotations) {
		// Выполнение прямых ротаций
		while ((*a) != min_cost_elem) {
			ra(a);  // Прямая ротация
		}
	} else {
		// Выполнение обратных ротаций
		while ((*a) != min_cost_elem) {
			rra(a);  // Обратная ротация
		}
	}
} */

void	advance_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;

	push_to_b(a, b);
	while (*a)
	{
		min_cost = find_elem(*a, *b);
		printf("Element for rotation: %d\n", min_cost->value);
//		perform_rotations(a, min_cost);
//		pb(a, b);
	}
}
