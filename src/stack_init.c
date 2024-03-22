/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:43:06 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 22:43:06 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
    while (stack != NULL)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

t_stack *init_stack(int argc, char *argv[])
{
    t_stack *stack;
    t_stack *new_node;
    int i;
    int value;
    int error;

    stack = NULL;
    i = argc - 1;
    error = 0;
    if (argc < 2)
        exit(EXIT_FAILURE);
    while (i > 0)
    {
        value = parse_arg(argv[i], &error);
        if (error || has_duplicate(stack, value))
            exit_error(stack);
        new_node = stack_new_node(value);
        if (!new_node)
            exit(EXIT_FAILURE);
        stack_add_top(&stack, new_node);
        i--;
    }
    return stack;
}
