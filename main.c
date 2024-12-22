/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:00:07 by onajem            #+#    #+#             */
/*   Updated: 2024/12/22 21:44:14 by onajem           ###   ########.fr       */
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

// int	is_valid(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	if (arg[i] != '+' && arg[i] != '-' && !(arg[i] >= '0' && arg[i] <= '9'))
// 		return (1);
// 	if ((arg[i] == '+' || arg[i] == '-') && 
// 	!(arg[i + 1] >= '0' && arg[i + 1] <= '9'))
// 		return (1);
// 	++i;
// 	while (arg[i])
// 	{
// 		if (!(arg[i] >= '0' && arg[i] <= '9'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

stack *create_stack(char **av)
{
	stack *list;
	stack *node;
	char *str;
	size_t words;
	size_t i;

	str = NULL;
	i = 1;
	list = NULL;
    while (av[i])
    {
		str = ft_strjoin(str , av[i]);
		str = ft_strjoin(str , " ");
        i++;
    }
	av = ft_split(str, ' ',  &words);
	free(str);
	i = words;
	while (i > 0 )
	{
		node = node_init(ft_atol(av[i - 1]));
		if (!node)
		{
			// free array
			write(2, "Error\n", 6);
			return (0);
		}
		add_node(&list, node);
		i--;
	}
	free_array(av, words);
	return (list);
}

void gg()
{
	system("leaks push_swap");
}

int main(int ac, char **av)
{
	stack *a;
	int len;
	
    if (ac < 2)
        return (0);
	else if (ac == 2 && !av[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = create_stack(av);
	if (is_sorted(a) == 0)
	{
		len = size(a);
		printf("process : \n");
		if (size(a) == 2)
			sa(&a);
		else if (size(a) == 3)
			tiny_sort(&a);	
		else
			push_swap(&a, &len);
	}
	ft_lstclear(&a);
    return (0);
}
