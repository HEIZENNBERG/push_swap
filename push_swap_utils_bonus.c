/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:22:34 by onajem            #+#    #+#             */
/*   Updated: 2024/12/28 18:54:12 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static long	check_overflow(long long num, char digit, int is_neg)
{
	if (num > LLONG_MAX / 10
		|| (num == LLONG_MAX / 10 && (digit - '0') > LLONG_MAX % 10))
	{
		if (is_neg == -1)
			return (LONG_MIN);
		else if (is_neg == 1)
			return (LONG_MAX);
	}
	return (1);
}

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	num_start(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

long	ft_atol(const char *nptr)
{
	int			sign;
	long long	sum;

	sum = 0;
	sign = num_start(&nptr);
	while (is_num(*nptr))
	{
		if (check_overflow(sum, *nptr, sign) != 1)
			return (check_overflow(sum, *nptr, sign));
		sum = sum * 10 + (*nptr - '0');
		nptr++;
	}
	return (sum * sign);
}

int	is_sorted(t_stack *a)
{
	int	check;

	check = 0;
	while (a->next && a->nb < a->next->nb)
		a = a->next;
	if (!a->next)
		check = 1;
	return (check);
}
