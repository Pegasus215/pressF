/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:33:43 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:30:11 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int size)
{
	char	*temp;
	int		i;

	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[size] = 0;
	return (temp);
}
