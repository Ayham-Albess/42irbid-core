#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list {
	int value;
	struct s_list* next;
	struct s_list* previous;
}t_stack;


void	sort(t_stack** a, t_stack** taila, char **argv, int argc);//begin the sorting according to the disorder or the flags

void	Simple(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb);//Simple sorting with O(n*2) complexity

void	Medium(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb);//Medium sorting with O(n(sqrn)) complexity

void	Complex(t_stack **a,  t_stack **taila, t_stack **b, t_stack **tailb);//Complex sorting with O(nlogn) complexity

//Part of the Medium sorting 
void	sort_p_Medium(int *p);//to sort the array of integers.
int	find_index(int *p, int value);//find the index of a specific value in p.
void	set_index(t_stack **a, int *p);//exchange the elements in a to there indisis in p.
int	window_size(int len);//to inisialize the window size.


//operations frome the subject 
//********************************
void	sa(t_stack** a, int c);
void	sb(t_stack** b, int c);
void	ss(t_stack** a, t_stack** b);
void	pa(t_stack** a, t_stack **b);
void	pb(t_stack **a, t_stack** b);
void	ra(t_stack** a, t_stack** tail, int c);
void	rb(t_stack** b, t_stack** tail, int c);
void	rr(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb);
void	rra(t_stack** a, t_stack** tail ,int c);
void	rrb(t_stack** b, t_stack** tail, int c);
void	rrr(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb);
//********************************

char	**ft_split(char const *s, char c);//to split the input if it's a string

int	stack_len(t_stack* s);//to calculate the stack length 

int	sorted(t_stack* s);//to check if the stack is sorted or not.

float	disorder(t_stack* a, t_stack* tail);//to calculate the disorder that detremine the algo will be using

int	*valid(char **s);//to check if the stack is valid

void	sort_by_disorder(t_stack **a, t_stack **tail_a, t_stack **b, t_stack ** tail_b);//to begin sorting by disorder

int	match_flag(char* s);//to check if the string is one of the flags

int	length(char **s);//to calculate the length of two-dimensional array

t_stack* ft_lstnew(int value);//to create a node of a spicific value


#endif
