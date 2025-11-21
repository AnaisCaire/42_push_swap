
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	// ajouter position, prix des mouvements, position final
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

t_node  *ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
t_node  *ft_lstnew(int content)
{
	t_node  *node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = content;
	node->next = NULL;
	return (node);
}


void    ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node  *last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	reverse_rotate(t_node **stack)
{
	t_node  *last;
	t_node	*prev;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	} 
	prev->next = NULL; //detach the last
	last->next = *stack; // pit last in front
	*stack = last;
} 


int  main()
{
	t_node  *first = ft_lstnew(1);
	t_node  *sec = ft_lstnew(2);
	t_node  *tird = ft_lstnew(3);

	t_node *lst = first;

	ft_lstadd_back(&lst, sec);
	ft_lstadd_back(&lst, tird);

	reverse_rotate(&lst);
	//swap(&lst);

	printf("%d\n", (int)lst->value);
	printf("%d\n", (int)lst->next->value);
	printf("%d\n", (int)lst->next->next->value);

	free(first);
	free(sec);
	free(tird);
}
