/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:40:34 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:47 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
		{
			last = lst;
			return (last);
		}
		lst = lst->next;
	}
	return (last);
}
