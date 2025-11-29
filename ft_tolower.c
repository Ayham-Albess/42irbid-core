#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}
/*
int main()
{
	char c = '1';
	char p = ft_tolower(c);
	printf("%c",p);
}
*/
