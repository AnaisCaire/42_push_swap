/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:07:25 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/27 12:33:43 by acaire-d         ###   ########.fr       */
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

static t_node	*biggest(t_node *stack)
{
	int		big;
	t_node	*biggest_n;

	big = -2147483647;
	while (stack)
	{
		if (stack->value > big)
		{
			big = stack->value;
			biggest_n = stack;
		}
		stack = stack->next;
	}
	return (biggest_n);
}

static void	bring_to_top(t_node **a, t_node *target)
{
	int		len;
	int		pos;
	t_node	*tmp;

	if (!a || !*a || !target)
		return ;
	len = ft_stacklen(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp != target)
	{
		pos++;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (pos <= len / 2)
		while (*a != target)
			ra(a);
	else
		while (*a != target)
			rra(a);
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

void	five_sort(t_node **a, t_node **b)
{
	int		len;
	t_node	*max;

	if (a == NULL || *a == NULL)
		return ;
	len = ft_stacklen(*a);
	while (len > 3)
	{
		max = biggest(*a);
		bring_to_top(a, max);
		pb(a, b);
		len--;
	}
	small_sort(a);
	while (b && *b)
	{
		pa(a, b);
		ra(a);
	}
}
