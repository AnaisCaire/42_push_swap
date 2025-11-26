/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:50:43 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/26 17:27:16 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *strnb)
{
	if (strnb == NULL || *strnb == '\0')
		return (0);
	if (*strnb == '+' || *strnb == '-')
		strnb++;
	if (!(*strnb >= '0' && *strnb <= '9'))
		return (0);
	while (*++strnb)
	{
		if (!(*strnb >= '0' && *strnb <= '9'))
			return (0);
	}
	return (1);
}

int	duplicate_check(t_node *a, long nb)
{
	while(a)
	{
		if (a->value == nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_lstfree(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_freematrix(char **argv)
{
	int	i;

	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_error(t_node **stack, char **argv)
{
	ft_lstfree(stack);
	ft_freematrix(argv);
	write(1, "Error\n", 6);
	exit (1);
}
