/* 
make a program that is the string are not made of numbers, 
or -/+ then return 0
*/

#include <stdio.h>
static int long	ft_atol(char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

int	duplicate_check(t_node *a, long nb)
{
	int i;

	i=0;
	while(argv[i])
	{
		if 
	}
}


int main()
{
	char *tests[] = {1, 3, 5, 4, 1, 7};
	int i = 0;

	while (tests[i])
	{

	}
}
