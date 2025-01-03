/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:00:07 by onajem            #+#    #+#             */
/*   Updated: 2025/01/03 15:56:31 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] != '+' && str[i] != '-'
		&& !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	if ((str[i] == '+' || str[i] == '-') && (!str[i + 1]
			|| !(str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (0);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static char	*join_arguments(char **av)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 1;
	while (av[i])
	{
		if (is_valid_arg(av[i]) == 0)
			return (NULL);
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	return (str);
}

static t_stack	*create_t_stack(char **av)
{
	t_stack	*list;
	t_stack	*node;
	char	*str;
	size_t	words;
	size_t	i;

	list = NULL;
	str = join_arguments(av);
	if (!str)
		return (NULL);
	av = ft_split(str, ' ', &words);
	free(str);
	i = words;
	while (i > 0)
	{
		node = node_init(av[--i]);
		if (!node)
			return (ft_lstclear(&list), free_array(av, words), NULL);
		if (check_duplicate(list, node->nb))
			add_node(&list, node);
		else
			return (ft_lstclear(&list), free_array(av, words),
				free(node), NULL);
	}
	return (free_array(av, words), list);
}

static void	p_err(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	else if (ac == 2 && !av[1][0])
		return (p_err(), 1);
	a = create_t_stack(av);
	b = NULL;
	if (!a)
	{
		p_err();
		return (ft_lstclear(&a), 1);
	}
	process_stack(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	return (ft_lstclear(&a), 0);
}
