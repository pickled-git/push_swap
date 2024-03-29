/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:11 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/29 17:15:07 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third)
		ra(stack_a);
	else if (first < second && first > third)
		rra(stack_a);
	else if (first < third && second > third)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_stack(t_stack **stack_a)
{
	t_stack *stack_b;
	int size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	/*	else if (size <= 100)
		{
			// Использовать быструю сортировку или сортировку слиянием для больших наборов
			quick_sort(stack_a, stack_b);
		}
		else
		{
			// Для очень больших наборов данных (более 100 элементов)
			// Можно использовать более сложный алгоритм или комбинацию алгоритмов
			advanced_sort(stack_a, stack_b);
		}
	}*/
	free_stack(stack_b);
}