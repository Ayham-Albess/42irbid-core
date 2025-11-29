#include <stddef.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n && a[i] && b[i] && a[i] == b[i])
		i++;
	if (i == n)
		return (0);
	return (a[i] - b[i]);
}
/*
int main()
{
	char *c1 = "ayham";
	char *c2 = "ayham";
	int res = ft_strncmp(c1,c2,5);
	printf("%d",res);
}
*/
