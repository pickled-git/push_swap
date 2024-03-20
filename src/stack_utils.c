/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:44:47 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 22:44:47 by oprosvir         ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd) //из libft, убрать
{
    if (s)
        while (*s)
            write(fd, s++, 1);
}

int	ft_isdigit(int c) //из libft, убрать
{
    return (c >= '0' && c <= '9');
}