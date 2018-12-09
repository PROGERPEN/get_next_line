/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:01:35 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/02 15:13:17 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *next_link;
	t_list *begin_lst;
	t_list *begin_next;

	if (!lst || !f)
		return (NULL);
	next_link = lst->next;
	begin_lst = f(lst);
	begin_next = begin_lst;
	lst = next_link;
	while (lst)
	{
		next_link = lst->next;
		new_list = f(lst);
		lst = next_link;
		begin_lst->next = new_list;
		begin_lst = begin_lst->next;
	}
	return (begin_next);
}
