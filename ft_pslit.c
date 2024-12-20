/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:45:50 by onajem            #+#    #+#             */
/*   Updated: 2024/12/20 14:55:43 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	get_lim(char const *s, char c, size_t *start, size_t *end)
{
	while (s[*end] == c)
		(*end)++;
	*start = *end;
	while (s[*end] != c && s[*end])
		(*end)++;
}

static void	fill_array(char *dest, const char *s, size_t *start, size_t *end)
{
	size_t	i;

	i = 0;
	while (*start < *end)
		dest[i++] = s[(*start)++];
	dest[i] = '\0';
}

void	*free_array(char **s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c, size_t *words)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	**dest;

	if (!s)
		return (NULL);
	*words = count_words(s, c);
	dest = (char **)malloc((*words + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest[*words] = NULL;
	i = 0;
	start = 0;
	end = 0;
	while (i < *words)
	{
		get_lim(s, c, &start, &end);
		dest[i] = (char *)malloc(end - start + 1);
		if (!dest[i])
			return (free_array(dest, i));
		fill_array(dest[i++], s, &start, &end);
	}
	return (dest);
}