/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:00:07 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 18:24:03 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	set_prefix(char *dst, char const *src, size_t i, size_t s_len)
{
	while (i < s_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = ' ';
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

// void gg()
// {
// 	system("leaks a.out");
// }


int main(int ac, char **av)
{
	// atexit(gg);
    size_t i;
	stack *list;
	stack *node;
	char *str;
	size_t words;
	
    if (ac < 2)
        return (0);
    i = 1;
	str = NULL;
	list = NULL;
    while (av[i])
    {
		str = ft_strjoin(str , av[i]);
		str = ft_strjoin(str , " ");
        i++;
    }
	av = ft_split(str, ' ',  &words);
	i = words;
	while (i > 0)
	{
		node = node_init(ft_atol(av[i - 1]));
		if (!node)
		{
			write(1, "Error\n", 6);
			break;
		}
		add_node(&list, node);
		i--;
	}
	swap(&list);
	stack *tmp = list;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
	tmp = NULL;
	ft_lstclear(&list);
	free(str);
	free_array(av, words);
    return (0);
}
