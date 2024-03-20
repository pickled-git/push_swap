/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:14:51 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 17:49:52 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_node **lst, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}

void	print_stack(t_node *stack)
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
	t_node		*stack_a;
	t_node		*stack_b;
	int			i;
	long int	nb;
	t_node		*new_node;

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

// Implement stack operations here
void	push(t_node **stack, int value)
{
	// Push an element onto the stack
}

int	pop(t_node **stack)
{
	// Pop an element off the stack
	return (0); // Placeholder return value
}

void	swap(t_node **stack)
{
	// Swap the top two elements of the stack
}

void	rotate(t_node **stack)
{
	// Rotate all elements up by one
}

void	reverse_rotate(t_node **stack)
{
	// Rotate all elements down by one
}

// You will also need functions to sort the stack and to handle parsing and error-checking of input.