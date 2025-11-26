
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				keep;
	int				index; // placement
	int				lis; // 1 if its LIS
	int				pos;
	int				target_pos;
	int				cost_b;
	int				cost_a;
	struct s_node 	*next;
	struct s_node 	*prev;
}					t_node;

char	**normalize_input(int argc, char **argv);
void	ft_lstfree(t_node **stack);
void ft_freeall(t_node *a, t_node *b, char **str);


// operations

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	sa(t_node **a);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);


void	small_sort(t_node **a);
void	five_sort(t_node **a, t_node **b);
char	**ft_split(char *str);
void	ft_stackinit(t_node **a, char **argv);
int		ft_sorted(t_node *a);
void	ft_lstaddnode(t_node **stack, long int nb);
int		syntax_error(char *strnb);
int		duplicate_check(t_node *a, long nb);
void	free_error(t_node **stack, char **argv);
void	ft_freematrix(char **argv);
int		ft_stacklen(t_node *stack);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

//longest inscresing subsequence

void    push_non_lis_to_b(t_node **a, t_node **b, int lis_len);
void    mark_lis_nodes(t_node *a, int *in_lis);
int		find_lis(int *idx, int size, int **lis_arr);
int		mark_lis(int *idx, int size, int *len, int *prev, int **lis_arr);
void	lis_dp(int *idx, int size, int *len, int *prev);
void	ft_LIS(t_node **a, t_node **b);
int		*build_index_array(t_node *a, int size);

// the greedy algo

void		ft_greedy(t_node **a, t_node **b);
void		ft_get_pos(t_node *a, t_node *b);
void		ft_set_target(t_node *a, t_node *b);
void		set_cost(t_node *a, t_node *b);
t_node 		*get_cheapest_node(t_node *b);
void 		ft_rotation(t_node **a, t_node **b, t_node *best);
void	ft_final_rotate(t_node **a);

#endif
