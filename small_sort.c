/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:07:25 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/17 14:35:48 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_node *a)
{
	if (a == NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_node	*biggest(t_node *stack) // why is it t_node and not int ? also, why *
{
	int 	big;
	t_node 	*biggest_N;

	big = -2147483647;
	while(stack)
	{
		if (stack->value > big)
		{
			big = stack->value;
			biggest_N = stack;
		}
		stack = stack->next;
	}
	return (biggest_N);
}

void	small_sort(t_node **a)
{
	
}