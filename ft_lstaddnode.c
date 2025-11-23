/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:19:31 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/21 13:10:56 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node   *ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddnode(t_node **stack, long int nb)
{
	t_node *node;
	t_node *last_node;

	if (stack == NULL) //stack is already de double pointer dont forget = begining 
		return ;
	node = malloc(sizeof(t_node));
	if(!node)
		return ;
	node->next = NULL;
	node->value = nb;
	node->keep = 0;
	node->index = 0;
	node->lis = 0;
	if (*stack == NULL) //this refers to the list
	{
		*stack = node; //node is now the head
		node->prev = NULL;	//make sure there is no previous node
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int		ft_stacklen(t_node *stack)
{
	int len = 0;
	while(stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
