/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:57:45 by onajem            #+#    #+#             */
/*   Updated: 2024/12/27 18:25:50 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;	

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if ((char)c == '\0')
		return (1);
	return (0);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		check;

	i = 0;
	check = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
		{
			check = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (check);
}

static int set_instra(char *line, t_stack ***a, t_stack ***b)
{
    if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(*a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(*b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(*a, *b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(*b, *a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(*a, *b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(*a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(*b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(*a, *b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(*a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(*b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(*a, *b);
    else
        return (0);
    return (1);
}

void process_stack(t_stack **a, t_stack **b)
{
    char    *line;
    
    line = get_next_line(0);
    while (line)
    {
		printf("%s", line);
        if(!set_instra(line, &a, &b))
            {
                free(line);
                ft_lstclear(a);
            }
        free(line);
        line = get_next_line(0);
    }
}