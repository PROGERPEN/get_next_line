/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhrazz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:58:04 by fkhrazz           #+#    #+#             */
/*   Updated: 2018/12/02 13:25:59 by fkhrazz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_pointer;

	if (!alst || !del || !(*alst))
		return ;
	while (*alst)
	{
		next_pointer = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = next_pointer;
	}
}
