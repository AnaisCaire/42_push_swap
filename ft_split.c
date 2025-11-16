
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    ft_strlcpy(char *dest, const char *src, int len)
{
        int i = 0, lensrc =0;
        while(src[lensrc])
                lensrc++;
        if (len > 0)
        {
                while((i+1) < len && src[i])
                {
                        dest[i] = src[i];
                        i++;
                }
                dest[i] = '\0';
        }
        return(len);
}

int     ft_isspace(char c)
{
        if (c == '\t' || c == ' ' || c == '\n')
                return (1);
        return (0);
}

int     ft_count(char *s)
{
        int i = 0;
        int count = 0;
        int inside;
        while(s[i])
        {
                inside = 0;
                if (s[i] && ft_isspace(s[i]))
                        i++;
                while (s[i] && !ft_isspace(s[i]))
                {
                        if(!inside)
                        {
                                count++;
                                inside = 1;
                        }
                        i++;
                }
        }
        return (count);
}

int     ft_fill(char *s, char **arr)
{
        int i = 0, j =0, len =0;

        while(s[i])
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
                        if(!arr[j])
                                return (0);
                        ft_strlcpy(arr[j], s + i - len, len + 1);
                        j++;
                }
        }
        arr[j] = NULL;
        return(1);
}

char    **ft_split(char *str)
{
        int count = 0;
        char **arr;

        count = ft_count(str);
        printf("%d\n", count);
        arr = malloc(sizeof(char *) * (count + 1));
        if (!arr)
                return (NULL);
        ft_fill(str, arr);
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

