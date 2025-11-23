# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anais <anais@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 12:56:25 by acaire-d          #+#    #+#              #
#    Updated: 2025/11/23 16:49:25 by anais            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

#make a folder for the .o files

SRC		= main.c \
		  ft_operations.c \
		  ft_stackinit.c \
		  ft_split.c \
		  ft_errors.c \
		  ft_lstaddnode.c \
		  small_sort.c \
		  ft_push.c \
		  ft_LIS.c \
		  ft_LIS_utils.c

OBJ		= $(SRC:.c=.o)

OBJS_ALL = $(OBJ)

all: $(NAME)

$(NAME): $(OBJS_ALL)
	$(CC) $(CFLAGS) $(OBJS_ALL) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
