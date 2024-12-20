/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:58:32 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 18:07:00 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(stack **head)
{
    stack  *tmp;
    
    if (!head || !(*head) || !((*head)->next))
        return ;
    tmp = (*head);
    (*head) = (*head)->next;
    tmp->next = (*head)->next;
    (*head)->next = tmp;
}

void sa(stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}
void sb(stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}
void ss(stack **a, stack **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

// void pb(stack *a, stack *b)
// {
    
// }