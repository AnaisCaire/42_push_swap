/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:50:03 by anais             #+#    #+#             */
/*   Updated: 2025/11/23 22:50:05 by anais            ###   ########.fr       */
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
	t_node	*curr;

	if (!a || len <= 0)
		return ;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return ;
	curr = a;
	i = 0;
	while (curr)
	{
		arr[i++] = curr->value;
		curr = curr->next;
	}
	sort_array(arr, len);
	curr = a;
	while (curr)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == curr->value)
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
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
