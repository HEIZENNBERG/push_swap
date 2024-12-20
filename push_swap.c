/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:00:07 by onajem            #+#    #+#             */
/*   Updated: 2024/12/19 21:26:19 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "push_swap.h"
#include <stdio.h>

static void	set_prefix(char *dst, char const *src, size_t i, size_t s_len)
{
	while (i < s_len)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_srtdup(s2));
	if (!s2 && s1)
		return (ft_srtdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc(len_s1 + len_s2 + 1);
	if (!dest)
		return (NULL);
	i = 0;
	set_prefix(dest, s1, i, len_s1);
	while (i < len_s2)
	{
		dest[i + len_s1] = s2[i];
		i++;
	}
	dest[len_s1 + len_s2] = '\0';
	return (dest);
}

int main(int ac, char **av)
{
    int i;
    char *str;
    if (ac < 2)
        return (0);
    i = 1;
    while (ac > i)
    {

        printf("%s\n", av[i]);
        i++;
    }

    return (0);
}