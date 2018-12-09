/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:30:54 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 16:03:10 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new_sub;
	char *new_sub_begin;

	if (!s)
		return (NULL);
	new_sub = ft_strnew(len);
	if (!new_sub)
		return (NULL);
	new_sub_begin = new_sub;
	while (len > 0)
	{
		*new_sub = s[start];
		new_sub++;
		start++;
		len--;
	}
	*new_sub = '\0';
	return (new_sub_begin);
}
