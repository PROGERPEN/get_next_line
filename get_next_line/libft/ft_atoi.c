/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:55:35 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/01 16:23:51 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			flag;
	long long	parse_number;
	long long	check;

	flag = 1;
	parse_number = 0;
	while (*str == '\n' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = parse_number;
		parse_number = (parse_number * 10) + (*str++ - '0');
		if (parse_number < check)
			return (flag == 1 ? (-1) : 0);
	}
	return (flag * parse_number);
}
