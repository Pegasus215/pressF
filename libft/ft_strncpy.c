/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:33:40 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/14 14:33:41 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		else
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
	}
	res = dest;
	return (res);
}
