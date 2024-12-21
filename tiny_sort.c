/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:29:07 by onajem            #+#    #+#             */
/*   Updated: 2024/12/21 12:00:56 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack *max_node(stack *head)
{
    stack *max;

    if (!head)
        return NULL; 

    max = head;
    while (head)
    {
        if (head->nb > max->nb)
            max = head;
        head = head->next;
    }
    return max;
}

void tiny_sort(stack **a)
{
    stack *max;

    if (!a || !(*a))
        return ;
    max = max_node(*a);
    printf(" => %d\n", max->nb);
    if (max == *a)
        ra(a);
    else if ((*a)->next == max)
        rra(a);
    if ((*a)->nb > (*a)->next->nb)
        sa(a);
}
