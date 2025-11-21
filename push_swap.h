
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node 	*next;
	struct s_node 	*prev;
}					t_node;

void	ra(t_node **a);
void	sa(t_node **a);
void	rra(t_node **a);
void	small_sort(t_node **a);
char	**ft_split(char *str);
void	ft_stackinit(t_node **a, char **argv);
int		ft_sorted(t_node *a);
void	ft_lstaddnode(t_node **stack, long int nb);
int		syntax_error(char *strnb);
int		duplicate_check(t_node *a, long nb);
void	free_error(t_node **stack, char **argv);
int		ft_stacklen(t_node *stack);
#endif
