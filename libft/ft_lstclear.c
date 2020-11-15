/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:24:54 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:48 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*begin;

	begin = *lst;
	if (!(*lst))
		return ;
	while (begin)
	{
		temp = begin->next;
		del(begin->content);
		free(begin);
		begin = temp;
	}
	*lst = NULL;
}
