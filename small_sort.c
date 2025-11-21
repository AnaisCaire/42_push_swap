/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:07:25 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/21 12:43:02 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_node *a)
{
	if (a == NULL)
		return (0);
	while (a->next)
	{
		if ((a->value) > (a->next->value))
			return (0);
		a = a->next;
	}
	return (1);
}

static t_node	*biggest(t_node *stack) // if not a pointer, ca return que la valeur de la node et pas la node au complet
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
	t_node	*high_node;
	
	if (*a == NULL)
		return ;
	high_node = biggest(*a);
	if (high_node == (*a))
		ra(a);
	else if (high_node == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
