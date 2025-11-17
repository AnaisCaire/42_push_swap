/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:19:31 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/17 12:23:27 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *ft_lstlast(t_node *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next != NULL)
                lst = lst->next;
        return (lst);
}

void	ft_lstaddnode(t_node **stack, long int nb)
{
	t_node *node;
	t_node *last_node;

	node = malloc(sizeof(t_node));  // here why dont we take the size of nb ?
	if(!node)
		return ;
	if (stack == NULL)
		return ;
	node->next = NULL;
	node->value = nb;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;	//why put the value of the previous as NULL?
	}
	else
	{
		last_node  = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}