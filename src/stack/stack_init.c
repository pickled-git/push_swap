/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:43:06 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/29 18:44:09 by oprosvir         ###   ########.fr       */
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

static int	add_number_to_stack(t_stack **stack, const char *str)
{
	int		value;
	int		error;
	t_stack	*new_node;

	error = 0;
	value = parse_arg(str, &error);
	if (error || has_duplicate(*stack, value))
		return (-1);
	new_node = stack_new_node(value);
	if (!new_node)
		return (-1);
	stack_add_top(stack, new_node);
	return (0);
}

static void	fill_stack_from_string(t_stack **stack, char *str)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	if (!numbers)
		exit_error(*stack);
	i = 0;
	while (numbers[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		if (add_number_to_stack(stack, numbers[i]) == -1)
		{
			free(numbers[i]);
			numbers[i] = NULL;
			exit_cleanup(*stack, numbers);
		}
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
	{
		if (argv[1] == NULL || *trim_whitespace(argv[1]) == '\0')
			exit_error(stack);
		fill_stack_from_string(&stack, argv[1]);
	}
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			if (add_number_to_stack(&stack, argv[i]) == -1)
				exit_error(stack);
			i--;
		}
	}
	return (stack);
}
