/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:14:51 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 19:36:59 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new_node)
{
	if (new_node)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

// Your main program logic goes here
// Parse arguments and fill the stack
int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	long int nb;
	t_stack *new_node;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
	nb = 0;
	while (i > 0)
	{
		nb = atoi(argv[i]);
		new_node = ft_lstnew(nb);
		if (!new_node)
			exit(EXIT_FAILURE);
		ft_lstadd_front(&stack_a, new_node);
		i--;
	}
	printf("Stack A:\n");
	print_stack(stack_a);
	return (0);
}