/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:45:06 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/02 14:01:27 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *next_list;

	if (!lst && !f)
		return ;
	while (lst)
	{
		next_list = lst->next;
		f(lst);
		lst = next_list;
	}
}
