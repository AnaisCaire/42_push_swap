/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:54:03 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/17 14:05:44 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// controle derreur 

int long ft_atol(char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
    {
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

void	ft_stackinit(t_node **a, char **argv)
{
	int i = 0;
	int nb = 0;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		//if repetitions
		//if not a number
		// if syntax error
		ft_lstaddnode(*a, nb);
		i++;
	}
}

