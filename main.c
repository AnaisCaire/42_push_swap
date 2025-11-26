/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:00:12 by anais             #+#    #+#             */
/*   Updated: 2025/11/26 17:57:10 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
ARG=$(seq -1000 1000 | sort -R | head -n 50 | tr '\n' ' '); 
./push_swap $ARG | ./checker_linux $ARG
*/

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	split = normalize_input(argc, argv);
	if (!split)
		return (1);
	ft_stackinit(&a, split);
	if (!ft_sorted(a))
	{
		if (ft_stacklen(a) == 2)
			sa(&a);
		else if (ft_stacklen(a) == 3)
			small_sort(&a);
		else if (ft_stacklen(a) == 5)
			five_sort(&a, &b);
		else
			ft_greedy(&a, &b);
	}
	ft_freeall(a, b, split);
	return (0);
}
