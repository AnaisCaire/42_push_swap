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
	len = 0;
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
			arr[j] = malloc(sizeof(*arr[j]) * (len + 1));
			if (!arr[j])
				return (j);
			ft_strlcpy(arr[j], s + i - len, len + 1);
			j++;
		}
	}
	arr[j] = NULL;
	return (j); //better to return how many were filled after failure 
}

static void	free_partial(char **arr, int filled)
{
	int	k;

	if (!arr)
		return ;
	k = 0;
	while (k < filled)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
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
	filled = ft_fill(str, arr);
	if (filled < count && count > 0)
	{
		/* ft_fill filled up to index `filled` before failing */
		free_partial(arr, filled);
		return (NULL);
	}
	return (arr);
}

/* int  main()
{
	int     i = 0;
	char    string[] = "this is a test      ok \n hahahaha";
	char    **test = ft_split(string);
	while(test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
} */
