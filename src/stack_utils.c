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

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str)) // Use ft_isdigit to ensure character is a digit
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
			exit_error(); // Exit with error if outside integer bounds
		str++;
	}
	if (*str != '\0')
		// If there are remaining characters after number processing
		exit_error(); // Exit with error if any non-digit characters are found
	return ((int)(res * sign));
}
