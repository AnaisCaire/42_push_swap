/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:38:00 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/21 13:08:38 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last;
	t_node	*first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	first = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
