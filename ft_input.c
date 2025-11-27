/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:32:24 by anais             #+#    #+#             */
/*   Updated: 2025/11/27 12:58:22 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static size_t	ft_arglen(int argc, char **argv)
{
	size_t	total;
	int		i;

	total = 0;
	i = 1;
	while (i < argc)
		total += ft_strlen(argv[i++]) + 1;
	return (total);
}

static void	fill_joined(char *joined, int argc, char **argv)
{
	size_t	pos;
	size_t	j;
	int		i;

	i = 1;
	pos = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			joined[pos++] = argv[i][j++];
		if (i < argc - 1)
			joined[pos++] = ' ';
		i++;
	}
	joined[pos] = '\0';
}

static char	*join_args(int argc, char **argv)
{
	char	*joined;
	size_t	total;

	total = ft_arglen(argc, argv);
	if (total == 0)
		return (NULL);
	joined = malloc(total + 1);
	if (!joined)
		return (NULL);
	fill_joined(joined, argc, argv);
	return (joined);
}

char	**normalize_input(int argc, char **argv)
{
	char	*joined;
	char	**split;

	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	split = ft_split(joined);
	free(joined);
	return (split);
}
