/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:49:08 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:50 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (!new)
		return ;
	begin = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}
