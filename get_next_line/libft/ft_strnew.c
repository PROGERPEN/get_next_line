/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:28:20 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/11/26 16:57:54 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*c;
	char	*c_begin;
	size_t	i;

	i = 0;
	c = (char *)malloc(sizeof(char) * (size + 1));
	if (!c)
		return (NULL);
	c_begin = c;
	while (i < size + 1)
	{
		c[i] = '\0';
		i++;
	}
	return (c_begin);
}
