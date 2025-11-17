/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:38:00 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/17 15:26:09 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node  *last;
	t_node	*first;

	if (*stack == NULL || stack == NULL) //add if stack is smaller than 2...
		return ; 
	last = *stack;
	first = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}
void	swap(t_node **stack)
{
	t_node  *first;
	t_node	*second;
	int		temp;

	if (*stack == NULL || stack == NULL) //add if stack is smaller than 2...
		return ; 
	first = *stack;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}