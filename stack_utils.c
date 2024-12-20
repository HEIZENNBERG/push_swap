/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:19:01 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 14:53:32 by onajem           ###   ########.fr       */
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