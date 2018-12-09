/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:43:51 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/11/25 15:57:07 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *stack_begin;
	char *needle_begin;
	char *stack_hay_start;
	char *equal_start;

	stack_begin = (char *)haystack;
	if (!*needle)
		return ((char *)haystack);
	while (*stack_begin)
	{
		needle_begin = (char *)needle;
		if (*stack_begin == *needle_begin)
		{
			stack_hay_start = stack_begin;
			equal_start = stack_begin;
			while (*equal_start++ == *needle_begin++)
			{
				if (!*needle_begin)
					return (stack_hay_start);
			}
		}
		stack_begin++;
	}
	return ((char *)'\0');
}
