/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:27:18 by onajem            #+#    #+#             */
/*   Updated: 2025/01/02 16:24:18 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_stack **ab, t_stack *node, char c)
{
	if (!ab || !node || !(*ab))
		return ;
	while (*ab != node)
	{
		if (c == 'a')
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

static void	put_node_top_both(t_stack **a, t_stack **b, t_stack *node_a,
t_stack *node_b)
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

void	fill_a(t_stack **a, t_stack **b, int *len_a, int *len_b)
{
	t_stack	*lowest;

	lowest = get_low_cost(*b);
	put_node_top_both(a, b, lowest->target_node, lowest);
	push_node(b, lowest, 'b');
	push_node(a, lowest->target_node, 'a');
	pa(b, a);
	*len_a = size(*a);
	*len_b = size(*b);
}

int	is_valid_arg(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (1);
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}
