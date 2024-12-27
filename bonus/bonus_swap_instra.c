/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap_instra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:58:32 by onajem            #+#    #+#             */
/*   Updated: 2024/12/26 20:22:39 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head) || !((*head)->next))
		return ;
	tmp = (*head);
	(*head) = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
