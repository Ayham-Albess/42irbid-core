#include "push_swap.h"

int	ft_strcmp(const char* s1, const char* s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int	match_flag(char* s)
{
	if (ft_strcmp(s, "--simple"))
		return (1);
	else if (ft_strcmp(s, "--medium"))
		return (2);
	else if (ft_strcmp(s, "--complex"))
		return (3);
	else if (ft_strcmp(s, "--adaptive"))
		return (4);
	else if (ft_strcmp(s, "--bench"))
		return (5);
	else
		return (-1);
}

int	length(char **s)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

t_stack	*ft_lstnew(int value)
{
	t_stack* node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
