/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:49:57 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/26 17:26:52 by anais            ###   ########.fr       */
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
	curr =  b;
	while(curr)
	{
		curr->cost_b = curr->pos;
		if (curr->pos > size_b/2)
			curr->cost_b = curr->pos - size_b;
		curr->cost_a = curr->target_pos;
		if (curr->target_pos > size_a/2)
			curr->cost_a = curr->target_pos - size_a;
		curr = curr->next;
	}
}

t_node 		*get_cheapest_node(t_node *b)
{
	t_node	*curr;
	t_node	*best;
	int		total;
	long 	best_cost;
	int 	abs_a;
	int		abs_b;
	
	best_cost = 2147483647;
	curr = b;
	while (curr)
	{
		abs_a = (curr->cost_a < 0) ? -(curr->cost_a) : curr->cost_a;
		abs_b = (curr->cost_b  < 0) ? -(curr->cost_b) : curr->cost_b;
		if (has_same_sign(curr->cost_a, curr->cost_b))
			total  = (abs_a > abs_b) ? abs_a : abs_b;
		else
			total = abs_a + abs_b;
		if (total < best_cost)
		{
			best_cost = total;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}
