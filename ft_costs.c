/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:49:57 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/27 13:24:39 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_same_sign(int a, int b)
{
	return ((a >= 0 && b >= 0) || (a < 0 && b < 0));
}

void	set_cost(t_node *a, t_node *b)
{
	int		size_b;
	int		size_a;
	t_node	*curr;

	size_b = ft_stacklen(b);
	size_a = ft_stacklen(a);
	curr = b;
	while (curr)
	{
		curr->cost_b = curr->pos;
		if (curr->pos > size_b / 2)
			curr->cost_b = curr->pos - size_b;
		curr->cost_a = curr->target_pos;
		if (curr->target_pos > size_a / 2)
			curr->cost_a = curr->target_pos - size_a;
		curr = curr->next;
	}
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-(n));
	return (n);
}

static int	calc_total_cost(t_node *node)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(node->cost_a);
	abs_b = ft_abs(node->cost_b);
	if (has_same_sign(node->cost_a, node->cost_b))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

t_node	*get_cheapest_node(t_node *b)
{
	t_node	*curr;
	t_node	*best;
	long	best_cost;
	int		total;

	best = NULL;
	best_cost = 2147483647;
	curr = b;
	while (curr)
	{
		total = calc_total_cost(curr);
		if (total < best_cost)
		{
			best_cost = total;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}
