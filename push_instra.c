/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:22:58 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 20:24:57 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(stack **src, stack **dst)
{
    stack *tmp;

    if (!dst || !src || !(*src))
        return ;
    tmp = NULL;
    tmp = (*src)->next;
    (*src)->next = (*dst);
    (*dst) = (*src);
    (*src) = tmp;
}

void pa(stack **b, stack **a)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(stack **a, stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}