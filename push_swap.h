/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:56:41 by onajem            #+#    #+#             */
/*   Updated: 2024/12/23 15:45:34 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_stack
{
    struct s_stack *next;
    struct s_stack *target_node;
    int nb;
    int index;
    int cost;
    int lowest_cost;
    int is_above_med; 
}stack;


void    reverse(stack **head);
void    rotate(stack **head);
void    push(stack **src, stack **dst);
void    swap(stack **head);

void    ra(stack **a);
void    rb(stack **b);
void    rr(stack **a, stack **b);

void    pa(stack **b, stack **a);
void    pb(stack **a, stack **b);

void    rra(stack **a);
void    rrb(stack **b);
void    rrr(stack **a, stack **b);

void    sa(stack **a);
void    sb(stack **b);
void    ss(stack **a, stack **b);

stack *min(stack *a);
void	fill_a(stack **a, stack **b, int *len_a, int *len_b);
stack  *get_low_cost(stack *a);
void    set_cost(stack *b, int len_a,  int len_b);
void    set_target_node(stack *a, stack *b);
void    set_index(stack *a, int med);
void    push_swap(stack **a, int *len);
int     size(stack *a);
int     is_sorted(stack *a);
void    tiny_sort(stack **a);
stack   *tail(stack *tmp);
long	ft_atol(const char *nptr);
stack   *node_init(long nb);
void    add_node(stack **list, stack *node);
void    *free_array(char **s, int len);
char	**ft_split(char const *s, char c, size_t *words);
void    ft_lstclear(stack **lst);

#endif