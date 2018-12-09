/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:07:52 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 12:16:23 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_line;

	if (!s || !f)
		return (NULL);
	i = 0;
	new_line = ft_strnew(ft_strlen((char *)s));
	if (!new_line)
		return (NULL);
	while (*s)
	{
		new_line[i] = f(i, *s);
		s++;
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
