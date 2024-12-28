/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:02:30 by onajem            #+#    #+#             */
/*   Updated: 2024/12/28 17:55:28 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

int	check_duplicate(t_stack *a, int nb)
{
	while (a)
	{
		if (a->nb == nb)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	set_prefix(char *dst, char const *src, size_t i, size_t s_len)
{
	while (i < s_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = ' ';
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc(len_s1 + len_s2 + 2);
	if (!dest)
		return (NULL);
	i = 0;
	set_prefix(dest, s1, i, len_s1);
	while (i <= len_s2)
	{
		dest[i + len_s1] = s2[i];
		i++;
	}
	dest[len_s1 + len_s2] = '\0';
	return (free(s1), dest);
}
