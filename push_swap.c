/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:13:04 by onajem            #+#    #+#             */
/*   Updated: 2024/12/21 18:31:01 by onajem           ###   ########.fr       */
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

void push_swap(stack **a, int *len)
{
    int *arr;
    int med;
    stack *b;
    int len_b;
    
    if (!a || !(*a))
        return ;
        
    arr = (int *)malloc((*len) * sizeof(int));
    if (!arr)
        return ;
    b = NULL;
    med = fill_array(*a, arr, len);
    len_b = 0;
    while (*len > 3 && is_sorted(*a) == 0)
    {
        pb(a, &b);
        len_b++;
        if (size(b) != 0)
            {
                if (b->nb < med)
                    rrb(&b);
            }
    }
    stack *tmp;
    tmp = b;
    while (tmp)
    {
        printf("%d\n", tmp->nb);
        tmp = tmp->next;
    }
    free(arr);
    ft_lstclear(&b);
}
