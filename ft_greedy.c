/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:13 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/25 12:23:23 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack(const char *name, t_node *s) //temporary function
{
    printf("%s:\n", name);
    while (s)
    {
        printf("  val=%d idx=%d keep=%d\n", s->value, s->index, s->keep);
        s = s->next;
    }
}

void	ft_greedy(t_node **a, t_node **b)
{
	t_node	*best;

	ft_LIS(a, b);
	print_stack("A", *a);
	print_stack("B", *b);
	while (b)
	{
		ft_get_pos(*a, *b);
		ft_set_target(*a, *b);
		set_cost(*a, *b);
		best = get_cheapest_node(*b);
		ft_rotation(a, b, best);
		pa(a, b);
	}
}