/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:44:47 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 23:12:43 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_new_node(int content)
{
    t_stack	*new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = content;
    new_node->next = NULL;
    return (new_node);
}

void	stack_add_top(t_stack **lst, t_stack *new_node)
{
    if (new_node)
    {
        new_node->next = *lst;
        *lst = new_node;
    }
}

int	parse_arg(const char *str, int *error)
{
    long	res;
    int	sign;

    res = 0;
    sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == 32) // Пропускаем пробельные символы
        str++;
    if (*str == '-' || *str == '+') // Обработка знака
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') // Преобразование строки в число
    {
        res = res * 10 + (*str - '0');
        if (res > INT_MAX || (sign == -1 && -res < INT_MIN)) // Проверка на пределы int
        {
            *error = 1;
            return 0; // Немедленный выход из функции после установки ошибки
        }
        str++;
    }
    if (*str != '\0') // Проверка на наличие недопустимых символов после числа
    {
        *error = 1;
        return 0; // Немедленный выход из функции после установки ошибки
    }
    return ((int)(res * sign));
}

void	ft_putstr_fd(char *s, int fd) //из libft, убрать
{
    if (s)
        while (*s)
            write(fd, s++, 1);
}
