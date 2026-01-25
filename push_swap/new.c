#include "push_swap.h"

void	split_free(char** p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	init_a(int* p, t_stack** tail_a, t_stack **a)
{
	int i;

	i = 0;
	if (*a == NULL)
		*a = ft_lstnew(p[i++]);
	if (p[i])
	{
		*tail_a = ft_lstnew(p[i]);
		if (!*tail_a)
			return ;
		i++;
		(*a) ->next = *tail_a;
		(*tail_a) ->previous = *a;
		(*tail_a) ->next = NULL;
		while (p[i])
		{
			(*tail_a) ->next = ft_lstnew(p[i++]);
			(*tail_a) ->next->previous = *tail_a;
			*tail_a = (*tail_a) ->next;
			(*tail_a) ->next = NULL;
		}
	}
	else
		return ;
}

void	dup(t_stack *a)
{
	t_stack	*tmp;
	int	*p;
	int	i;
	int	j;

	tmp = a;
	i = 0;
	p = malloc(stack_len(a) * sizeof(int));
	while (tmp)
	{
		p[i++] = tmp ->value;
		tmp = tmp ->next;
	}
	i = 0;
	while (p[i])
	{
		j = i + 1;
		while (p[j])
			if (p[i] == p[j])
				error();
		i++;
	}
}

void	sort(t_stack** a, t_stack** taila, char **argv, int argc)
{
	t_stack* b;
	t_stack* tailb;
	int	i;

	dup(a);
	i = 0;
	b = NULL;
	tail_b = NULL;
	while (argv[i])
	{
		if (match_flag(argv[i]) == -1)
			i++;
		else if (match_flag(argv[i]) == 1)
			Simple();
		else if (match_flag(argv[i]) == 2)
			Medium();
		else if (match_flag(argv[i]) == 3)
			Complex();
		else if (match_flag(argv[i]) == 4)
			sort_by_disorder();
		else if (match_flag(argv[i]) == 5)
			Bench();
	}
	sort_by_disorder();
}

int main(int argc, char **argv)
{
	int	i;
	char	**args;
	int	*p;
	t_stack	*a;
	t_stack	*tail_a;

	a = NULL;
	tail_a = NULL;
	if (args < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i++] , ' ');
		if (!args)
			error();
		p = valid(args);
		if (!p)
			continue ;
		init_a(p, &tail_a, &a);
	}
	if (sorted(a))
		return (0);
	split_free(args);
	sort(&a, &tail_a, &argv, argc);
}
