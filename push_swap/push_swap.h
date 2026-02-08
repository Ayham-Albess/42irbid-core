#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <string.h>

typedef struct s_node
{
	int value;
	int index;
	struct s_node* next;
	struct s_node* prev;
}t_node;

typedef enum e_ops
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	TOTAL_OP,
	OP_COUNT
}t_ops;

typedef enum s_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}t_strategy;

typedef struct s_bench
{
	long counts[OP_COUNT];
}t_bench;

typedef struct s_stack
{
	t_node* head;
	t_node* tail;
	int size;
	t_bench* bench;
}t_stack;

typedef struct s_algo
{
	t_strategy strategy;
	int bench;
	int set;
}t_algo;

void	print_bench(t_stack *a, t_algo *algo, float disorder);//for bench printing

void	sort(t_stack *a, t_stack *b, t_algo *algo);//to begin sorting based on the flags or the disorder

void medium(t_stack *a, t_stack *b);//medium sorting with O(sqrn) complexcity

void simple(t_stack *a, t_stack *b);//simple sorting with O(n*n) complexcity

void	complexx(t_stack *a, t_stack *b);//complex sorting with O(nlogn) complexcty

void free_split(char **s);//free a double pointer array

int set_strategy(t_algo* algo, char* flag);//set the strategy (simple or medium or complex or adabtiv)

t_algo parse_flags(int* argc, char*** argv);//check thee flags in the input and remove it from argv

void push_stack(t_stack* a, long num);//push numbers to stack a

int get_numbers(int argc, char** argv, t_stack* a);//convert to integers and check if all are numbers and in the limit

float compute_disorder(t_stack *a);//compute the disorder


//operations
void	sa(t_stack *a, int c);
void	sb(t_stack *a, t_stack *b, int c);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, int c);
void	rb(t_stack *a, t_stack *b, int c);
void	rr(t_stack *a, t_stack *b);
void	rra (t_stack *a, int c);
void	rrb(t_stack *a,t_stack *b, int c);
void	rrr(t_stack *a, t_stack *b);
//*************************************

void	error();//handle the errors by exit


char	**ft_split(char const *s, char c);

int	has_dup(long num, t_stack* a);//check if there is duplicatesin stack a

int	number(char* s);//check if the string is numbers

int	sorted (t_stack *a);//check if the stack is sorted

long	ft_atoi(char *s);//convert string to integer

void indexing (t_stack *a);

void set_index(t_node *node, int *p, int size);

void sort_p(int *p, int size);

void    init_stack(t_stack *s);

void ft_memset(void *s, int c, size_t n);

void    ft_printf_d(int nbr);

void    ft_putchar(char c);

int     ft_strcmp(char *s1, char *s2);

#endif
