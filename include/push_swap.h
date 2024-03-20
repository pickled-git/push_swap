/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:13:00 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/20 19:34:31 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

// Define a struct for stack nodes
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// Function prototypes for stack operations
void				push(t_stack **stack, int value);
int					pop(t_stack **stack);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

#endif