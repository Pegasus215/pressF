/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:05:59 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:44 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int ch, size_t n)
{
	unsigned char	*temps;
	unsigned char	*tempd;
	unsigned char	c;

	c = ch;
	temps = src;
	tempd = dest;
	while (n--)
	{
		if ((*tempd++ = *temps++) == c)
			return (tempd);
	}
	return (NULL);
}
