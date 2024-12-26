/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:22:58 by onajem            #+#    #+#             */
/*   Updated: 2024/12/26 12:44:57 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!dst || !src || !(*src))
		return ;
	tmp = NULL;
	tmp = (*src)->next;
	(*src)->next = (*dst);
	(*dst) = (*src);
	(*src) = tmp;
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
