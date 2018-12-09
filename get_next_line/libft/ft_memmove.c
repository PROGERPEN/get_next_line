/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:00:59 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 12:53:07 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_start;
	char	*src_start;

	dst_start = (char *)dst;
	src_start = (char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len)
		{
			dst_start[len - 1] = src_start[len - 1];
			len--;
		}
	}
	while (len)
	{
		*dst_start++ = *src_start++;
		len--;
	}
	return (dst);
}
