
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include "push_swap.h"

typedef struct s_node
{
	int				value;
	// ajouter position, prix des mouvements, position final
	struct s_node 	*next;
	struct s_node 	*prev;
}			t_node;


#endif