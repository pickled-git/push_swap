/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:13:00 by oprosvir          #+#    #+#             */
/*   Updated: 2024/03/18 22:16:09 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Define a struct for stack nodes
typedef struct  s_node
{
    int value;
    struct s_node *next;
}               t_node;

// Function prototypes for stack operations
void push(t_node **stack, int value);
int pop(t_node **stack);
void swap(t_node **stack);
void rotate(t_node **stack);
void reverse_rotate(t_node **stack);