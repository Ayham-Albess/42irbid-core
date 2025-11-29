#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
		return (c);
}
/*
int main()
{
	char c = '1';
	char p = ft_toupper(c);
	printf("%c",p);
}
*/
