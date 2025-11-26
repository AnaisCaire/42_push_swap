/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:46:32 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/26 18:01:18 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}
static void rotate_a_only(t_node **a, int *cost_a)
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

static void rotate_b_only(t_node **b, int *cost_b)
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

void ft_rotation(t_node **a, t_node **b, t_node *best)
{
    int cost_a = best->cost_a;
    int cost_b = best->cost_b; //wewill update this as we do the rotations that why the *

    rotate_both(a, b, &cost_a, &cost_b);
    rotate_a_only(a, &cost_a);
    rotate_b_only(b, &cost_b);
}


static int	smallest_pos(t_node *a)
{
    t_node *cur = a;
    int min = INT_MAX;
    int pos = 0;
    int res = 0;

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
    int len;
    int pos;
    int moves;

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