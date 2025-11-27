/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:46:32 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/27 12:56:37 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_only(t_node **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	rotate_b_only(t_node **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	ft_rotation(t_node **a, t_node **b, t_node *best)
{
	int	cost_a;
	int	cost_b;

	cost_b = best->cost_b;
	cost_a = best->cost_a;
	rotate_both(a, b, &cost_a, &cost_b);
	rotate_a_only(a, &cost_a);
	rotate_b_only(b, &cost_b);
}

static int	smallest_pos(t_node *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		res;

	cur = a;
	min = 2147483647;
	pos = 0;
	res = 0;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			res = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (res);
}

void	ft_final_rotate(t_node **a)
{
	int	len;
	int	pos;
	int	moves;

	if (!a || !*a)
		return ;
	len = ft_stacklen(*a);
	pos = smallest_pos(*a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		moves = len - pos;
		while (moves-- > 0)
			rra(a);
	}
}
