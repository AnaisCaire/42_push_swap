/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:00:12 by anais             #+#    #+#             */
/*   Updated: 2025/11/21 13:11:54 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	char	**split;

	a = NULL;
	if (argc >= 2)
	{
		split = ft_split(argv[1]);
		ft_stackinit(&a, split);
		if (!ft_sorted(a))
		{
			if (ft_stacklen(a) == 2)
				sa(&a);
			else if (ft_stacklen(a) == 3)
				small_sort(&a);
		}
	}
	return (0);
}
