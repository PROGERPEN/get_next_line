/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:26:14 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/02 16:04:03 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_word_numbers(char const *s, char c)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (s[i] && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char		**ft_lines_inter(char **new_lines_arr, char const *s,
		char c, int words)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < words)
	{
		k = 0;
		while (*s == c)
			s++;
		while (s[k] != c)
			k++;
		new_lines_arr[i] = ft_strsub(s, 0, k);
		if (!new_lines_arr[i])
		{
			while (i--)
				free(new_lines_arr[i]);
			return (NULL);
		}
		i++;
		s += k;
	}
	return (new_lines_arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new_lines_arr;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_numbers(s, c);
	i = 0;
	new_lines_arr = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!new_lines_arr)
		return (NULL);
	new_lines_arr[words] = NULL;
	new_lines_arr = ft_lines_inter(new_lines_arr, s, c, words);
	if (!new_lines_arr)
	{
		free(new_lines_arr);
		return (NULL);
	}
	while (new_lines_arr[i])
	{
		i++;
	}
	return (new_lines_arr);
}
