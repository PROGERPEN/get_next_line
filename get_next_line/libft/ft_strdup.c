/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:26:09 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 15:54:10 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newline;
	char	*start_s1;
	char	*start_newline;
	int		c;

	start_s1 = (char *)s1;
	c = 0;
	while (*start_s1)
	{
		c++;
		start_s1++;
	}
	newline = (char *)malloc(sizeof(char) * c + 1);
	if (!newline)
		return (NULL);
	start_newline = newline;
	while (*s1)
	{
		*newline = *s1;
		newline++;
		s1++;
	}
	*newline = '\0';
	return (start_newline);
}
