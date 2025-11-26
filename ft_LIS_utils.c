/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_LIS_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:58:44 by anais             #+#    #+#             */
/*   Updated: 2025/11/26 17:27:52 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_dp(int *idx, int size, int *len, int *prev)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (idx[j] < idx[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}


static int	*alloc_in_lis(int size)
{
	int	*in_lis;
	int	i;

	in_lis = malloc(sizeof(int) * size);
	if (!in_lis)
		return (NULL);
	i = 0;
	while (i < size)
	{
		in_lis[i] = 0;
		i++;
	}
	return (in_lis);
}

static int	get_best_end(int *len, int size, int *best_len)
{
	int	i;
	int	best_end;

	i = 0;
	*best_len = 0;
	best_end = 0;
	while (i < size)
	{
		if (len[i] > *best_len)
		{
			*best_len = len[i];
			best_end = i;
		}
		i++;
	}
	return (best_end);
}

int	mark_lis(int *idx, int size, int *len, int *prev, int **lis_arr)
{
	int	*in_lis;
	int	best_len;
	int	best_end;
	int	i;

	in_lis = alloc_in_lis(size);
	if (!in_lis)
		return (0);
	best_end = get_best_end(len, size, &best_len);
	i = best_end;
	while (i != -1)
	{
		in_lis[idx[i]] = 1;
		i = prev[i];
	}
	*lis_arr = in_lis;
	return (best_len);
}
