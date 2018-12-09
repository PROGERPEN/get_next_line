/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:39:15 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 16:04:34 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_line;
	char	*new_line_begin;
	int		l;
	int		k;

	l = 0;
	if (!s)
		return (NULL);
	k = ft_strlen(s) - 1;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && l != k)
		l++;
	while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && l != k)
		k--;
	if (l == k)
		return (ft_strnew(0));
	new_line = ft_strnew((k - l) + 1);
	if (!new_line)
		return (NULL);
	new_line_begin = new_line;
	while (l <= k)
	{
		*new_line++ = s[l];
		l++;
	}
	return (new_line_begin);
}
