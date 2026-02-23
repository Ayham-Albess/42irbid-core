/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbess <aalbess@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:41:14 by aalbess           #+#    #+#             */
/*   Updated: 2026/02/09 15:59:19 by aalbess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

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
}					t_ops;

typedef enum s_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

typedef struct s_bench
{
	long			counts[OP_COUNT];
}					t_bench;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	t_bench			*bench;
}					t_stack;

typedef struct s_algo
{
	t_strategy		strategy;
	int				bench;
	int				set;
}					t_algo;

// for bench printing
void				print_bench(t_stack *a, t_algo *algo, float disorder);

// to begin sorting based on the flags or the disorder
void				sort(t_stack *a, t_stack *b, t_algo *algo);

// medium sorting with O(sqrn) complexcity
void				medium(t_stack *a, t_stack *b);

// simple sorting with O(n*n) complexcity
void				simple(t_stack *a, t_stack *b);

// complex sorting with O(nlogn) complexcty
void				complexx(t_stack *a, t_stack *b);

// free a double pointer array
void				free_split(char **s);

// push numbers to stack a
void				push_stack(t_stack *a, long num);

// convert to integers and check if all are numbers and in the limit
int					get_numbers(int argc, char **argv, t_stack *a);

// set the strategy (simple or medium or complex or adabtiv)
int					set_strategy(t_algo *algo, char *flag);

// compute the disorder
float				compute_disorder(t_stack *a);

// check thee flags in the input and remove it from argv
t_algo				parse_flags(int *argc, char ***argv);

//////////////////////////////////////////////////
// operations
void				sa(t_stack *a, int c);
void				sb(t_stack *a, t_stack *b, int c);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a, int c);
void				rb(t_stack *a, t_stack *b, int c);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a, int c);
void				rrb(t_stack *a, t_stack *b, int c);
void				rrr(t_stack *a, t_stack *b);
//*************************************

void				error(void); // handle the errors by exit
void				indexing(t_stack *a);
void				free_stack(t_stack *a);
void				set_index(t_node *node, int *p, int size);
void				sort_p(int *p, int size);
void				init_stack(t_stack *s);
void				ft_memset(void *s, int c, size_t n);
void				ft_printf_d(int nbr);
void				ft_putchar(char c);
void				valid(t_stack *a, char **tmp, int j);
void				push_to_b(t_stack*a, t_stack*b, int chunk_size);
void				back_to_a(t_stack*a, t_stack*b);
char				**ft_split(char const *s, char c);

long				ft_atoi(char *s);// convert string to integer
// check if there is duplicatesin stack a
int					dupp(long num, t_stack *a);
int					num(char *s);// check if the string is numbers
int					sorted(t_stack *a);// check if the stack is sorted
int					ft_strcmp(char *s1, char *s2);
int					get_pos(t_stack *s, int val);
int					*stack_to_sorted_array(t_stack *a);
int					get_min(t_stack *s);
int					calculate_chunk(int size);
int					get_position(t_node*top, int target_index);
int					get_max_index(t_stack *s);
int					lm(long num);

#endif
