/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:50:03 by anais             #+#    #+#             */
/*   Updated: 2025/11/24 11:51:16 by acaire-d         ###   ########.fr       */
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

static int	*sort_stack_to_arr(t_node *a, int len)
{
	int		i;
	int		*arr;
	t_node	*curr;

	if (!a || len <= 0)
		return (0);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	curr = a;
	i = 0;
	while (curr && i < len)
	{
		arr[i++] = curr->value;
		curr = curr->next;
	}
	sort_array(arr, len);
	return (arr);
}

static void	create_index(t_node *a, int *arr, int len)
{
	t_node	*curr;
	int		i;
	
	curr = a;
	while(curr)
	{
		i = 0;
		while(i < len)
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
}

static int		*stack_to_index_array(t_node *a, int len)
{
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (a && i < len)
	{
		arr[i++] = a->index;
		a = a->next;
	}
	return (arr);
}


int	*build_index_array(t_node *a, int size)
{
	int	*arr;
	int	*idx;

	arr = sort_stack_to_arr(a, size);
	if (!arr)
		return (NULL);
	create_index(a, arr, size);
	free(arr);
	idx = stack_to_index_array(a, size);
	return (idx);
}