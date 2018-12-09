/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:47:04 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/11/26 16:13:41 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				flag;
	unsigned char	stops;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	stops = (unsigned char)c;
	flag = 1;
	while (n > 0)
	{
		if (*b == stops)
		{
			*a = stops;
			a++;
			flag = -1;
			return (a);
		}
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (NULL);
}
