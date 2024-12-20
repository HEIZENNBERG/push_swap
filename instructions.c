/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:58:32 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 15:15:05 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(stack *nd1, stack *nd2)
{
    int tmp;
    tmp = nd1->nb;
    nd1->nb = nd2->nb;
    nd2->nb = tmp;
}

void sa(stack *a)
{
    swap(a, a->next);
}
void sb(stack *b)
{
    swap(b, b->next);
}
void ss(stack *a, stack *b)
{
    sa(a);
    sb(b);
}

void pb(stack *a, stack *b)
{
    
}