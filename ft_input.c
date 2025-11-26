/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:32:24 by anais             #+#    #+#             */
/*   Updated: 2025/11/26 15:15:16 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t  ft_strlen(const char *str)
{
        size_t  len;

        len = 0;
        while (str[len])
                len++;
        return (len);
}

static char	*join_args(int argc, char **argv)
{
	char	*joined;
	size_t	total;
	size_t	pos;
	size_t	j;
	int		i;

	total = 0;
	i = 1;
	while (i < argc)
		total += ft_strlen(argv[i++]) + 1;
	if (total == 0)
		return (NULL);
	joined = malloc(total + 1);
	if (!joined)
		return (NULL);
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
