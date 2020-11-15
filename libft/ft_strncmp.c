/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:31:38 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:31 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t				res;
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)string1;
	s2 = (unsigned char *)string2;
	res = 0;
	i = 0;
	while ((s1[i] || s2[i]) && res == 0 && i < num)
	{
		if (s1[i] != s2[i])
			res = s1[i] - s2[i];
		i++;
	}
	return (res);
}
