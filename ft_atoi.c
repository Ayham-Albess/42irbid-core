#include <stddef.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n')
		*nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		*nptr++;
	}
	else if (*nptr == '+')
		*nptr++;
	else if (*nptr == '+' || *nptr == '-')
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		*nptr++;
	}
	return (sign * result);
}
/*
int main ()
{
	char *p = "    -ass1131";
	int res = ft_atoi(p);
	printf("%d",res);
}
*/
