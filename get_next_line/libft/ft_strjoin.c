/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:52:06 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/05 17:14:47 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_line;
	char	*p;

	if (!s2)
		return (NULL);
	new_line = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new_line)
		return (NULL);
	p = new_line;
	while (*s1)
		*new_line++ = *s1++;
	while (*s2)
		*new_line++ = *s2++;
	*new_line = '\0';
	return (p);
}
