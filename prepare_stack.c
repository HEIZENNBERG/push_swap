/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:49:56 by onajem            #+#    #+#             */
/*   Updated: 2024/12/22 21:04:55 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(stack *a, int med)
{
    int i;

    i = 0;
    if (!a)
        return ;
    while (a)
    {
        a->index = i;
        if (i <= med)
            a->is_above_med = 1;
        else if (i >= med)
            a->is_above_med = 0;
        a = a->next;
        i++;
    }
}

stack *min(stack *a)
{
    stack *dest;

    if (!a)
        return (NULL);
    dest = a;
    while (a)
    {   
        if (a->nb < dest->nb)
            dest = a;
        a = a->next;
    }
    return (dest);
}

void set_target_node(stack *a, stack *b)
{
    stack *tmp;
    stack *target;
    long    closest;

    while (b)
    {
        closest = LONG_MAX;
        tmp = a;
        while (tmp)
        {
            if (tmp->nb > b->nb && tmp->nb < closest)
            {
                closest = tmp->nb;
                target = tmp;
            }
            tmp = tmp->next;
        }
        if (closest == LONG_MAX)
            b->target_node = min(a);
        else 
            b->target_node = target;
        b = b->next;
    }
}

void    set_cost(stack *b, int len_a,  int len_b)
{

    while (b != NULL)
    {
        if (b->is_above_med == 0)
            b->cost = len_b - b->index;
            
        if (b->is_above_med == 1)
            b->cost = b->index;
            
        if (b->target_node->is_above_med == 0)
            b->cost += len_a - b->target_node->index;
            
        if (b->target_node->is_above_med == 1)
            b->cost += b->target_node->index;
            
        b = b->next;
    }
}

stack  *get_low_cost(stack *a)
{
    stack *tmp;

    if (!a)
        return (NULL);
    tmp = a;
    while (a)
    {   
        if (a->cost < tmp->cost)
            tmp = a;
        a = a->next;
    }
    return (tmp);
}