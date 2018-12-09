/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:42:28 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/02 17:14:08 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;
	unsigned char c_uns;

	c_uns = (unsigned char)(c % 256);
	src = (unsigned char *)s;
	while (n--)
	{
		if (*src == c_uns)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
