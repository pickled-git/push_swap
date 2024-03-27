/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:43:06 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/27 22:22:40 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	has_duplicate(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	add_number_to_stack(t_stack **stack, const char *str)
{
	int		value;
	int		error;
	t_stack	*new_node;

	error = 0;
	value = parse_arg(str, &error);
	if (error || has_duplicate(*stack, value))
		exit_error(*stack);
	new_node = stack_new_node(value);
	if (!new_node)
		exit_error(*stack);
	stack_add_top(stack, new_node);
}

static void	fill_stack_from_string(t_stack **stack, char *str)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	i = 0;
	while (numbers[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		add_number_to_stack(stack, numbers[i]);
		free(numbers[i]);
	}
	free(numbers);
}

t_stack	*init_stack(int argc, char *argv[])
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	if (argc == 2)
		fill_stack_from_string(&stack, argv[1]);
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			add_number_to_stack(&stack, argv[i]);
			i--;
		}
	}
	return (stack);
}
