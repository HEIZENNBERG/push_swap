/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:19:01 by onajem            #+#    #+#             */
/*   Updated: 2024/12/28 18:54:01 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*node_init(char *str)
{
	t_stack	*node;
	long	nb;

	if (!str || !is_valid(str))
		return (NULL);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (NULL);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->cost = 0;
	node->index = 0;
	node->is_above_med = 0;
	node->target_node = NULL;
	node->next = NULL;
	return (node);
}

void	add_node(t_stack **list, t_stack *node)
{
	if (!list || !node)
		return ;
	node->next = *list;
	*list = node;
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

t_stack	*tail(t_stack *tmp)
{
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	size(t_stack *a)
{
	int	i;

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
