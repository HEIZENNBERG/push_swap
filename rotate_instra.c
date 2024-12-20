/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:29:44 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 20:43:22 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void rotate(stack **head)
{
    stack *tmp;
    stack *last;

    if (!head || !(*head) || !(*head)->next)
        return ;
    tmp = *head;
    (*head) = (*head)->next;
    last = tail(*head);
    last->next = tmp;
    tmp->next = NULL;
}

void ra(stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(stack **b)
{
    rotate(b);
    write(1, "ra\n", 3);
}

void rr(stack **a, stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}