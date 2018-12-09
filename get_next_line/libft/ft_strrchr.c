/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:25:14 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/11/25 13:42:39 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *s_begin;

	s_begin = (char *)s;
	while (*s_begin)
		s_begin++;
	if (*s_begin == c)
		return (s_begin);
	s_begin--;
	while (*s_begin && s_begin >= s)
	{
		if (*s_begin == c)
			return ((char *)s_begin);
		s_begin--;
	}
	return (0);
}
