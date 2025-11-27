/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:11:41 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/27 12:15:44 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_pos(t_node *a, t_node *b)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = a;
	while (curr)
	{
		curr->pos = i++;
		curr = curr->next;
	}
	i = 0;
	curr = b;
	while (curr)
	{
		curr->pos = i++;
		curr = curr->next;
	}
}

static int	smallest_index_a(t_node *a)
{
	t_node	*curr;
	int		target_idx;
	int		target_pos;

	curr = a;
	target_pos = 0;
	target_idx = 2147483647;
	while (curr)
	{
		if (curr->index < target_idx)
		{
			target_idx = curr->index;
			target_pos = curr->pos;
		}
		curr = curr->next;
	}
	return (target_pos);
}

static int	find_target_pos_in_a(t_node *a, int b_index)
{
	int		target_pos;
	int		target_idx;
	t_node	*curr;

	target_pos = 0;
	target_idx = 2147483647;
	curr = a;
	while (curr)
	{
		if (curr->index > b_index && curr->index < target_idx)
		{
			target_idx = curr->index;
			target_pos = curr->pos;
		}
		curr = curr->next;
	}
	if (target_idx != 2147483647)
		return (target_pos);
	target_pos = smallest_index_a(a);
	return (target_pos);
}

void	ft_set_target(t_node *a, t_node *b)
{
	t_node	*curr;

	curr = b;
	while (curr)
	{
		curr->target_pos = find_target_pos_in_a(a, curr->index);
		curr = curr->next;
	}
}
