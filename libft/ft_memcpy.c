/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:49:28 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:41 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*temps;
	unsigned char		*tempd;

	temps = src;
	tempd = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*tempd++ = *temps++;
	return (dest);
}
