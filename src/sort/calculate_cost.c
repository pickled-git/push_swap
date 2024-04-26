/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:53:28 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/26 19:57:51 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *b, int value)
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

static int	rotate_cost(int *cost_a, int *cost_b)
{
	int	total;

	total = 0;
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		total++;
	}
	return (total);
}

static int	reverse_rotate_cost(int *cost_a, int *cost_b)
{
	int	total;

	total = 0;
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		total++;
	}
	return (total);
}

static int	combined_rotation_cost(int cost_a, int cost_b)
{
	int	total_cost;

	total_cost = 0;
	if (cost_a > 0 && cost_b > 0)
	{
		total_cost = rotate_cost(&cost_a, &cost_b);
		total_cost += cost_a + cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		total_cost = reverse_rotate_cost(&cost_a, &cost_b);
		total_cost += ft_abs(cost_a) + ft_abs(cost_b);
	}
	else
		total_cost = ft_abs(cost_a) + ft_abs(cost_b);
	return (total_cost);
}

int	calculate_cost(t_stack *a, t_stack *b, int value)
{
	int	pos_b;
	int	pos_a;
	int	cost_b;
	int	cost_a;

	pos_b = find_position(b, value);
	pos_a = find_index(a, value);
	cost_b = rotation_cost(stack_size(b), pos_b);
	cost_a = rotation_cost(stack_size(a), pos_a);
	return (combined_rotation_cost(cost_a, cost_b));
}
