/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:52:08 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:40 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, const int value, size_t size)
{
	unsigned char *ptr;

	ptr = dest;
	if (size == 0)
		return (dest);
	while (size-- > 0)
		*ptr++ = value;
	return (dest);
}
