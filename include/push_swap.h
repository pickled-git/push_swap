/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:13:00 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 23:09:00 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Define a struct for stack nodes
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack *init_stack(int argc, char *argv[]);
t_stack	*stack_new_node(int content);
void	stack_add_top(t_stack **lst, t_stack *new_node);
void    free_stack(t_stack *stack);
void	exit_error(t_stack *stack);
void	ft_putstr_fd(char *s, int fd); ////из libft, убрать
int	is_sorted(t_stack *stack);
int	parse_arg(const char *str, int *error);

#endif