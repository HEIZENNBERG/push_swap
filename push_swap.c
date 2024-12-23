/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:13:04 by onajem            #+#    #+#             */
/*   Updated: 2024/12/23 15:54:23 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int   med_sort_array(int *arr, int *size)
{
    int    i;
    int    j;
    int    temp;

    i = 0;
    while (i < *size - 1)
    {
        j = 0;
        while (j < *size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    return (arr[*size / 2]);
}

static int fill_array(stack *a, int *arr, int *len)
{
    int i;

    if (!a || !arr)
        return (0);
    i = 0;
    while (a)
    {
        arr[i] = a->nb;
        a = a->next;
        i++;
    }
    med_sort_array(arr, len);
    return (arr[i / 2]);
}

void prepare_stacks(stack *a, stack *b, int len_a, int len_b)
{
    set_index(a, len_a / 2);
    set_index(b, len_b / 2);
    set_target_node(a, b);
    set_cost(b, len_a, len_b);
}

static void	put_min_on_top(stack **a)
{
    stack *lowest;
    
    lowest = min(*a);
	while ((*a)->nb != lowest->nb)
	{
		if (lowest->is_above_med == 1)
			ra(a);
		else
			rra(a);
	}
}

void push_swap(stack **a, int *len_a)
{
    int *arr;
    int med;
    stack *b;
    int len_b;
    
    if (!a || !(*a))
        return ;
        
    arr = (int *)malloc((*len_a) * sizeof(int));
    if (!arr)
        return ;
    b = NULL;
    med = fill_array(*a, arr, len_a);
    len_b = 0;
    while (*len_a > 3 && is_sorted(*a) == 0)
    {
        pb(a, &b);
        len_b++;
        if (b->nb < med && size(b))
            rb(&b);
        (*len_a)--;
    }
    tiny_sort(a);
    while (b)   
    {
        prepare_stacks(*a, b, *len_a, len_b);
        fill_a(a, &b, len_a, &len_b);
    }
    set_index(*a, *len_a / 2);
    put_min_on_top(a);
    free(arr);
    ft_lstclear(&b);
}


    
    // stack *tmp;
    // tmp = *a;
    // while (tmp)
    // {
    //     printf("%d\n", tmp->nb);
    //     tmp = tmp->next;
    // }