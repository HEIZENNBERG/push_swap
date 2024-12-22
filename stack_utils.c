/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:19:01 by onajem            #+#    #+#             */
/*   Updated: 2024/12/22 20:34:56 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack *node_init(long nb)
{
    stack *node;

    node = (stack *)malloc(sizeof(stack));
    if (!node || nb > INT_MAX || nb < INT_MIN)
        return (NULL);
    node->nb = nb;
    node->cost = 0;
    node->index = 0;
    node->is_above_med = 0;
    node->target_node = NULL; 
    node->next = NULL;
    return (node);
}

void add_node(stack **list, stack *node)
{
    if (!list || !node)
        return ;
    node->next = *list;
    *list = node;
}

void	ft_lstclear(stack **lst)
{
	stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

stack *tail(stack *tmp)
{
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

int size(stack *a)
{
    int i;
    
    if (!a)
        return (0);
    i = 0;
    while (a)
    {
        a = a->next;
        i++;
    }
    return (i);
}