/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:36:26 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 13:37:01 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	lenght;
	size_t	new_line;

	new_line = 0;
	lenght = ft_strlen((char *)s2);
	while (*s1 && n > 0)
	{
		s1++;
		new_line++;
		n--;
	}
	while (*s2 && n > 1)
	{
		*s1 = *s2;
		s2++;
		n--;
		s1++;
		if (n == 1 || !*s2)
			*s1 = '\0';
	}
	return (lenght + new_line);
}
