/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:53:25 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/02 16:03:05 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_negative(long int *n, int *k, int *flag)
{
	if (*n < 0)
	{
		*k += 1;
		*n *= -1;
		*flag = -1;
	}
}

char			*ft_itoa(int n)
{
	char		*new_line;
	int			k;
	long int	n_begin;
	int			flag;
	long int	n_unsign;

	k = 0;
	flag = 0;
	n_unsign = n;
	ft_negative(&n_unsign, &k, &flag);
	n_begin = n_unsign;
	while (n_unsign /= 10)
		k++;
	k += 1;
	new_line = ft_strnew(k);
	if (!new_line)
		return (NULL);
	while (k-- >= 0)
	{
		new_line[k] = n_begin % 10 + '0';
		n_begin /= 10;
	}
	if (flag == -1)
		new_line[0] = '-';
	return (new_line);
}
