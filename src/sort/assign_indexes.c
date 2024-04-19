/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:44:12 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/16 11:00:28 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	fill_values(int *values, t_stack *node)
{
	int	index;

	index = 0;
	while (node != NULL)
	{
		values[index] = node->value;
		node = node->next;
		index++;
	}
}

static void	bubble_sort(int *values, int n)
{
	int	swapped;
	int	i;
	int	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (values[i] > values[i + 1])
			{
				tmp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
		n--; // Decrease n since the last element is now sorted
	}
}

static void	assign_index(t_stack *node, int *values, int size)
{
	int	index;

	while (node != NULL)
	{
		index = 0;
		while (index < size)
		{
			if (node->value == values[index])
			{
				node->index = index;
				break ;
			}
			index++;
		}
		node = node->next;
	}
}

void	assign_indexes(t_stack **stack_a)
{
	t_stack	*temp;
	int		size;
	int		*values;

	temp = *stack_a;
	size = stack_size(temp);
	values = malloc(sizeof(int) * size);
	if (values == NULL)
		return ;
	fill_values(values, temp);
	bubble_sort(values, size);
	assign_index(temp, values, size);
	free(values);
}
