/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:46:32 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/25 12:15:24 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);     // both up
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);    // both down
        (*cost_a)++;
        (*cost_b)++;
    }
}
static void rotate_a_only(t_node **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		cost_a++;
	}	
}

static void rotate_b_only(t_node **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		ra(b);
		cost_b--;
	}
	while (*cost_b < 0)
	{
		rra(b);
		cost_b++;
	}	
}

void ft_rotation(t_node **a, t_node **b, t_node *best)
{
    int cost_a = best->cost_a;
    int cost_b = best->cost_b; //wewill update this as we do the rotations that why the *

    rotate_both(a, b, &cost_a, &cost_b);
    rotate_a_only(a, &cost_a);
    rotate_b_only(b, &cost_b);
}