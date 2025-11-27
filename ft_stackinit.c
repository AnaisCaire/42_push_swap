/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:54:03 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/27 12:18:20 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int long	ft_atol(char *str)
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
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (argv[i])
	{
		if (!syntax_error(argv[i]))
			free_error(a, argv);
		nb = ft_atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			free_error(a, argv);
		if (!duplicate_check(*a, nb))
			free_error(a, argv);
		ft_lstaddnode(a, nb);
		i++;
	}
}

// test malloc function for ft_split.c

int	test_malloc(char **array, int pos, size_t buffer)
{
	int	j;

	j = 0;
	array[pos] = malloc(buffer);
	if (array[pos] == NULL)
	{
		while (j < pos)
			free(array[j++]);
		free(array);
		return (1);
	}
	return (0);
}
