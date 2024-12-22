/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:27:18 by onajem            #+#    #+#             */
/*   Updated: 2024/12/22 21:18:03 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_node(stack **ab, stack *node, char c)
{
    if (!ab || !node || !(*ab))
        return ;
    while (*ab != node)
    {
        if (c  == 'a')
        {
            if (node->is_above_med == 1)
                ra(ab);
            else 
                rra(ab);
        }
        else
            if (node->is_above_med == 1)
                rb(ab);
            else 
                rrb(ab);
    }
}

static void	put_node_top_both(stack **a, stack **b, stack *node_a, stack *node_b)
{
	while (*a != node_a && *b != node_b)
	{
		if (node_a->is_above_med && node_b->is_above_med)
			rr(a, b);
		else if (!(node_a->is_above_med) && !(node_b->is_above_med))
			rrr(a, b);
		else
			break ;
	}
}

void	fill_a(stack **a, stack **b)
{
    stack *lowest;

    lowest = get_low_cost(*b);
    put_node_top_both(a, b, lowest->target_node, lowest);
	push_node(b, lowest, 'b');
	push_node(a, lowest->target_node, 'a');
    pa(b, a);
}