/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_instrra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:44:09 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 20:59:00 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack *before_tail(stack *tmp)
{
    while (tmp && tmp->next && tmp->next->next)
        tmp = tmp->next;

    return tmp;
}

void reverse(stack **head)
{
    stack *last;
    stack *before_last;

    if (!head || !(*head) || !(*head)->next)
        return ;
    
    before_last = before_tail(*head);
    last = before_last->next;
    before_last->next = NULL;
    last->next = *head;
    *head = last;
}

void rra(stack **a)
{
    reverse(a);
    write(1, "rra\n", 4);
}

void rrb(stack **b)
{
    reverse(b);
    write(1, "rra\n", 4);
}

void rrr(stack **a, stack **b)
{
    reverse(a);
    reverse(b);
    write(1, "rrr\n", 4);
}