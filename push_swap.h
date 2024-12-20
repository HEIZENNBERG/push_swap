/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:56:41 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 18:04:05 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_stack
{
    int nb;
    struct s_stack *next;
}stack;

void    swap(stack **head);
long	ft_atol(const char *nptr);
stack   *node_init(long nb);
void    add_node(stack **list, stack *node);
void	*free_array(char **s, int len);
char	**ft_split(char const *s, char c, size_t *words);
void	ft_lstclear(stack **lst);

#endif