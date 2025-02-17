/* ************************************************************************** */
/*	                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:56:41 by onajem            #+#    #+#             */
/*   Updated: 2024/12/28 19:53:00 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*target_node;
	int				nb;
	int				index;
	int				cost;
	int				lowest_cost;
	int				is_above_med;
}t_stack;

void	reverse(t_stack **head);
void	rotate(t_stack **head);
void	push(t_stack **src, t_stack **dst);
void	swap(t_stack **head);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

int		is_valid_arg(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		is_valid(char *str);
int		check_duplicate(t_stack *a, int nb);
t_stack	*min(t_stack *a);
void	fill_a(t_stack **a, t_stack **b, int *len_a, int *len_b);
t_stack	*get_low_cost(t_stack *a);
void	set_cost(t_stack *b, int len_a, int len_b);
void	set_target_node(t_stack *a, t_stack *b);
void	set_index(t_stack *a, int med);
void	push_swap(t_stack **a, int *len);
int		size(t_stack *a);
int		is_sorted(t_stack *a);
void	tiny_sort(t_stack **a);
t_stack	*tail(t_stack *tmp);
long	ft_atol(const char *nptr);
t_stack	*node_init(char *str);
void	add_node(t_stack **list, t_stack *node);
void	*free_array(char **s, int len);
char	**ft_split(char const *s, char c, size_t *words);
void	ft_lstclear(t_stack **lst);

#endif
