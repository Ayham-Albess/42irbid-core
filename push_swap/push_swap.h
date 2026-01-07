/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:00:56 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/05 16:42:06 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

//Stack definition
typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*previous;
}	t_stack;

//Stack Utils
char	**ft_split(char const *s, char c);
int		stack_len(t_stack *t);
t_stack	*find_last_node(t_stack *t);
bool	sorted(t_stack *t);

//Disorder check
void	check_order(t_stack *a, t_stack *tail);

//Operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **tail);
void	rb(t_stack **b, t_stack **tail);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **tail);
void	rrb(t_stack **b, t_stack **tail);
void	rrr(t_stack **a, t_stack **b, t_stack **ta, t_stack **tb);

#endif
