#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !(argc == 2 && argv[1][0] == 0))
	{
		argv = ft_split(argv[1]);
		ft_stackinit(&a, argv + 1);
		if(!sorted(a))
		{
			if (argv == 3)
			{
				small_sort(a);
			}
		}
	}
	return (0);
}