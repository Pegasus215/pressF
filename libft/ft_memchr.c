/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:00:34 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:42 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char *ptr;
	unsigned char		ch;

	ch = c;
	ptr = src;
	while (n-- > 0)
	{
		if (*ptr == ch)
			return ((void*)ptr);
		ptr++;
	}
	return (NULL);
}
