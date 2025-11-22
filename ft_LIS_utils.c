/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_LIS_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:58:44 by anais             #+#    #+#             */
/*   Updated: 2025/11/22 16:08:09 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int len)
{
	int swapped;
	int	i;
	int tmp;
	
	if (!arr || len <= 1)
		return ;
	swapped = 1;
	while(swapped)
	{
		swapped = 0;
		i = 0;
		while( i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	sort_stack_to_arr(t_node *a, int len)
{
	int		i;
	int		*arr;
	t_node	*tmp;

	if (!a || len <= 0)
		return ;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return ;
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, len);
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

int		*stack_to_index_array(t_node *a, int len)
{
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->index;
		a = a->next;
	}
	return (arr);
}

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

int	mark_lis(int *idx, int size, int *len, int *prev, int **lis_arr)
{
	int	*in_lis;
	int	best_len;
	int	best_end;
	int	k;
	int	i;

	in_lis = malloc(sizeof(int) * size);
	if (!in_lis)
		return (0);
	i = 0;
	while (i < size)
		in_lis[i++] = 0;
	best_len = 0;
	best_end = 0;
	i = 0;
	while (i < size)
	{
		if (len[i] > best_len)
		{
			best_len = len[i];
			best_end = i;
		}
		i++;
	}
	k = best_end;
	while (k != -1)
	{
		in_lis[idx[k]] = 1;
		k = prev[k];
	}
	*lis_arr = in_lis;
	return (best_len);
}
