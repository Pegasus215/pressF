/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:30:53 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:45 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*curr;

	if (!(curr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	curr->content = content;
	curr->next = NULL;
	return (curr);
}
