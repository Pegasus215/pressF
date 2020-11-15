/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:15:29 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:41 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*temps;
	unsigned char		*tempd;
	const unsigned char	*lasts;
	unsigned char		*lastd;

	temps = src;
	tempd = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (tempd < temps)
	{
		while (n--)
			*tempd++ = *temps++;
	}
	else
	{
		lasts = temps + (n - 1);
		lastd = tempd + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
