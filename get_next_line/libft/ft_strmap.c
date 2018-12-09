/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:36:34 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 12:15:33 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new_line;
	char *new_line_begin;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	new_line = ft_strnew(ft_strlen((char *)s));
	if (!new_line)
		return (NULL);
	new_line_begin = new_line;
	while (*s)
	{
		*new_line = f(*s);
		s++;
		new_line++;
	}
	*new_line = '\0';
	return (new_line_begin);
}
