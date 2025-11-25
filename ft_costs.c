/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:49:57 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/25 12:05:47 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	set_cost(t_node *a, t_node *b)
{
	int		size_b;
	int		size_a;
	t_node	*curr;

	size_b = ft_stacklen(b);
	size_a = ft_stacklen(a);
	curr =  a;
	while(curr)
	{
		curr->cost_b = curr->pos;
		if (curr->pos > size_b/2)
			curr->cost_b = curr->pos - size_b;
		curr->cost_a = curr->target_pos;
		if (curr->target_pos > size_b/2)
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
	
	best_cost = 2147483647;
	curr = b;
	while (curr)
	{
		int abs_a;
		int	abs_b;

		abs_a = (curr->cost_a < 0) ? -(curr->cost_a) : curr->cost_a;
		abs_b = (curr->cost_b  < 0) ? -(curr->cost_b) : curr->cost_b;

		if(((curr->cost_b >= 0) && (curr->cost_a >= 0)) 
			|| ((curr->cost_b < 0) && (curr->cost_a < 0)))
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
