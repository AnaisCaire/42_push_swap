# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anais <anais@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 12:56:25 by acaire-d          #+#    #+#              #
#    Updated: 2025/11/26 17:48:27 by anais            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
OBJ_DIR	= bin
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

#make a folder for the .o files

SRC		= main.c \
		  ft_rotate.c \
		  ft_stackinit.c \
		  ft_split.c \
		  ft_errors.c \
		  ft_lstaddnode.c \
		  small_sort.c \
		  ft_push_swap.c \
		  ft_reverse_rotate.c \
		  ft_LIS.c \
		  ft_LIS_utils.c \
		  ft_stack_to_array.c \
		  ft_pos_target.c \
		  ft_costs.c \
		  ft_rotations.c \
		  ft_greedy.c \
		  ft_input.c

OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

OBJS_ALL = $(OBJ)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS_ALL)
	$(CC) $(CFLAGS) $(OBJS_ALL) -o $@

$(OBJ_DIR)/%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
