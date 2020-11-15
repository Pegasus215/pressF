/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:39:03 by ezachari          #+#    #+#             */
/*   Updated: 2020/10/30 15:07:25 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char *s;
	const char *found;

	found = NULL;
	if (ch == 0)
	{
		return (ft_strchr(str, 0));
	}
	else
	{
		while ((s = ft_strchr(str, ch)) != NULL)
		{
			found = s;
			str = s + 1;
		}
	}
	return ((char*)found);
}
