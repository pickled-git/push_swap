/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:44:12 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/02 02:33:22 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* 
 * fill_values - Recursively traverses the stack and populates the values array with the node values.
 * @values: The array to be populated with node values.
 * @node: The current node of the stack from which the filling starts.
 * @index: The current index in the values array where the node value will be placed.
 * This function is used to initialize the array of values, which will then be sorted.
 */
static void	fill_values(int *values, t_stack *node, int index)
{
    if (node == NULL)
        return ;
    values[index] = node->value;
    fill_values(values, node->next, index + 1);
}

/* 
 * bubble_sort - Recursive implementation of the bubble sort algorithm.
 * @values: The array of values to be sorted.
 * @n: The number of elements in the values array that need to be sorted.
 * @i: The current index in the array for comparison with the next element.
 * This function effectively sorts the elements of the array in ascending order.
 */
static void	bubble_sort(int *values, int n, int i)
{
    int	tmp;

    if (n == 1)
        return ;
    if (i < n - 1)
    {
        if (values[i] > values[i + 1])
        {
            tmp = values[i];
            values[i] = values[i + 1];
            values[i + 1] = tmp;
        }
        bubble_sort(values, n, i + 1);
    }
    else
        bubble_sort(values, n - 1, 0);
}

/* 
 * assign_index - Recursively assigns indexes to stack nodes based on the sorted values array.
 * @node: The current stack node to which an index will be assigned.
 * @values: The sorted array of values based on which the indexes are assigned.
 * @index: The current index in the values array for matching with the node.
 * @size: The size of the values array (or the total number of nodes in the stack).
 * This function sets the index for each node in the stack corresponding to its position in the sorted array.
 */
static void	assign_index(t_stack *node, int *values, int index, int size)
{
    if (node == NULL || index == size)
        return ;
    if (node->value == values[index])
    {
        node->index = index;
        assign_index(node->next, values, 0, size);
    }
    else
        assign_index(node, values, index + 1, size);
}

/* 
 * assign_indexes - The main function that coordinates the process of assigning indexes to stack nodes.
 * @stack_a: Pointer to the top of the stack whose nodes will be assigned indexes.
 * This function creates an array of values from the stack, sorts it, and assigns indexes to the stack nodes based on the sorted array.
 */
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
    fill_values(values, temp, 0);
    bubble_sort(values, size, 0);
    assign_index(temp, values, 0, size);
    free(values);
}

