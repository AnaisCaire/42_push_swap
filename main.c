/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:00:12 by anais             #+#    #+#             */
/*   Updated: 2025/11/22 16:16:22 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack(const char *name, t_node *s)
{
    printf("%s:\n", name);
    while (s)
    {
        printf("  val=%d idx=%d keep=%d\n", s->value, s->index, s->keep);
        s = s->next;
    }
}

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
					pushswap(&a, &b);
					print_stack("A", a);
					print_stack("B", b);
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
