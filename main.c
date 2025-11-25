/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:00:12 by anais             #+#    #+#             */
/*   Updated: 2025/11/25 12:04:06 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split;

	a = NULL;
	b = NULL;
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
				else if (ft_stacklen(a) == 5)
					five_sort(&a, &b);
				else
				{
					ft_greedy(&a, &b);
				}
			}
	}
	return (0);
}


/* 
python3 - <<'PY'
import random
nums = random.sample(range(1, 1001), 200)
print(" ".join(map(str, nums)))
PY

*/
