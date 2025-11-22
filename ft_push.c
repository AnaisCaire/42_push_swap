/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:45:04 by anais             #+#    #+#             */
/*   Updated: 2025/11/21 17:08:21 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*node;

	if (!a || !*a)
		return ;
	node = *a;
	*a = node->next;
	if (*a)
		(*a)->prev = NULL;
	node->next = *b;
	if (*b)
		(*b)->prev = node;
	node->prev = NULL;
	*b = node;
	write(1, "pb\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*node;

	if (!b || !*b)
		return ;
	node = *b;
	*b = node->next;
	if (*b)
		(*b)->prev = NULL;
	node->next = *a;
	if (*a)
		(*a)->prev = node;
	node->prev = NULL;
	*a = node;
	write(1, "pa\n", 3);
}
