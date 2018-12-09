/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:57:34 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/11/25 17:00:31 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while ((haystack[i] == needle[i]) && (len - i))
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack);
			i++;
		}
		len--;
		haystack++;
	}
	return (0);
}
