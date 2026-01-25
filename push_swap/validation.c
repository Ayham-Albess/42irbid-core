#include "push_swap.h"

int	valid2(char **s)
{
	if (!s)
		error();
	if (match_flag(*s) != -1)
		return (0);
	if (!number(s))
		error();
	else
		return (1);
}

void	putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	res = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	number(char** s)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] && s[i])
		{
			if (j == 0 && (s[i][j] == '-' || s[i][j] == '+'))
				j++;
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*valid(char **s)
{
	int	*res;
	int	len;
	int	i;
	int	j;

	if (valid2(s) == 0)
		return (NULL);
	i = 0;
	len = length(s);
	res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	len = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			res[len] = ft_atoi(s[i][j++]);
			if (res[len] > INT_MAX || res[len++] < INT_MIN)
				error();
		}
		i++;
	}
	return (res);
}
