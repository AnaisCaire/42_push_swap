/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaire-d <acaire-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:07:15 by acaire-d          #+#    #+#             */
/*   Updated: 2025/11/27 12:20:02 by acaire-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_strlcpy(char *dest, const char *src, int len)
{
	int	i;
	int	lensrc;

	i = 0;
	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	if (len > 0)
	{
		while ((i + 1) < len && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

static int	ft_count(char *s)
{
	int	i;
	int	count;
	int	inside;

	i = 0;
	count = 0;
	while (s[i])
	{
		inside = 0;
		if (s[i] && ft_isspace(s[i]))
			i++;
		while (s[i] && !ft_isspace(s[i]))
		{
			if (!inside)
			{
				count++;
				inside = 1;
			}
			i++;
		}
	}
	return (count);
}

static int	ft_fill(char *s, char **arr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		if (s[i] && ft_isspace(s[i]))
			i++;
		while (s[i] && !ft_isspace(s[i]))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			if (test_malloc(arr, j, len + 1))
				return (1);
			ft_strlcpy(arr[j], s + i - len, len + 1);
			j++;
		}
	}
	return (0);
}

char	**ft_split(char *str)
{
	int		count;
	char	**arr;
	int		filled;

	if (str == NULL || *str == '\0')
		return (NULL);
	count = ft_count(str);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	filled = ft_fill(str, arr);
	return (arr);
}
