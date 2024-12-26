/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:29:07 by onajem            #+#    #+#             */
/*   Updated: 2024/12/26 12:54:27 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_node(t_stack *head)
{
	t_stack	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head)
	{
		if (head->nb > max->nb)
			max = head;
		head = head->next;
	}
	return (max);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*max;

	if (!a || !(*a))
		return ;
	max = max_node(*a);
	if (max == *a)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
