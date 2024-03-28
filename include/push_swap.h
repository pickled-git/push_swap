/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:13:00 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/28 01:22:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack				*init_stack(int argc, char *argv[]);
t_stack				*stack_new_node(int content);
void				stack_add_top(t_stack **lst, t_stack *new_node);
void				free_stack(t_stack *stack);
void				exit_error(t_stack *stack);
void				exit_cleanup(t_stack *stack, char **numbers);
int					is_sorted(t_stack *stack);
int					parse_arg(const char *str, int *error);

#endif