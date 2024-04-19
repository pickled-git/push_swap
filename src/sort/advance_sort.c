/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:08:59 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/19 15:00:39 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_position(t_stack *b, int index)
{
    int pos = 0;
    t_stack *current = b;
    while (current && index < current->index)
    {
        pos++;
        current = current->next;
    }
    return pos;
}

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

void	advance_sort(t_stack **a, t_stack **b)
{
	t_stack *current;
    int pos;
	//запушим в b 2 верхних из a и отсортируем их
	push_to_b(a, b);
	print_stack_i(*b);
	//тестовая версия с возвратом поззиции (доделать)
	while (*a)
    {
        current = *a;
        pos = find_position(*b, current->index);  // Находим позицию для текущего элемента в стеке B

        if (pos == 0)  // Если текущий элемент должен быть на верху stack_b
        {
            pb(a, b);
        }
        else
        {
            // Сдвигаем элементы в B для корректной вставки
            while (pos > 0)
            {
                rb(b);
                pos--;
            }
            pb(a, b);

            // Восстанавливаем порядок в B после вставки
            for (int i = 0; i < stack_size(*b) - pos - 1; i++)
                rrb(b);
        }
    }

	// Перемещаем все элементы из stack_b обратно в stack_a
	while (*b)
		pa(a, b);
	rotate_to_index(a, 0);
	printf("Stack B:\n");
	print_stack_i(*b);
}