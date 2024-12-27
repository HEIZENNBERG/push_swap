/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse_instra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:44:09 by onajem            #+#    #+#             */
/*   Updated: 2024/12/26 20:22:44 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

t_stack	*before_tail(t_stack *tmp)
{
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

void	reverse(t_stack **head)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!head || !(*head) || !(*head)->next || size(*head) <= 1)
		return ;
	before_last = before_tail(*head);
	last = before_last->next;
	before_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
