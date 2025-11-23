/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_LIS.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:51:28 by anais             #+#    #+#             */
/*   Updated: 2025/11/23 22:50:33 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lis(int *idx, int size, int **lis_arr)
{
	int	*len;
	int	*prev;
	int	best;

	len = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!len || !prev)
	{
		free(len);
		free(prev);
		return (0);
	}
	lis_dp(idx, size, len, prev);
	best = mark_lis(idx, size, len, prev, lis_arr);
	free(len);
	free(prev);
	return (best);
}

//mark the elements that belong to the LIS
void    mark_lis_nodes(t_node *a, int *in_lis)
{
    while (a)
    {
        if (in_lis[a->index])
            a->keep = 1;
        else
            a->keep = 0;
        a = a->next;
    }
}

void    push_non_lis_to_b(t_node **a, t_node **b, int lis_len)
{
    int total = ft_stacklen(*a);
    int to_push = total - lis_len;

    while (to_push > 0)
    {
        if ((*a)->keep == 0)
        {
            pb(a, b);
            to_push--;
        }
        else
            ra(a);
    }
}

void	ft_LIS(t_node **a, t_node **b)
{
	int		size;
	int		*idx;
	int		*lis_arr;
	int		lis_len;

	if (a == NULL || *a == NULL || b == NULL)
		return ;
	size = ft_stacklen(*a);
	sort_stack_to_arr(*a, size);
	idx = stack_to_index_array(*a, size);
	if (!idx)
		return ;
	lis_arr = NULL;
	lis_len = find_lis(idx, size, &lis_arr);
	if (!lis_arr)
	{
		free(idx);
		return ;
	}
	mark_lis_nodes(*a, lis_arr);
	push_non_lis_to_b(a, b, lis_len);
	free(idx);
	free(lis_arr);
}
