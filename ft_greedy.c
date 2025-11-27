/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:13 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/25 14:25:29 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_greedy(t_node **a, t_node **b)
{
	t_node	*best;

	ft_lis(a, b);
	while (*b)
	{
		ft_get_pos(*a, *b);
		ft_set_target(*a, *b);
		set_cost(*a, *b);
		best = get_cheapest_node(*b);
		ft_rotation(a, b, best);
		pa(a, b);
	}
	ft_final_rotate(a);
}
