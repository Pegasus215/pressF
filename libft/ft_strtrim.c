/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:39:27 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:50:00 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		left;
	size_t		right;
	size_t		begin;

	left = 0;
	begin = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	right = ft_strlen(s1);
	while (s1[left] && ft_strchr(set, s1[left]))
		left++;
	while (right > left && ft_strchr(set, s1[right - 1]))
		right--;
	if (!(str = (char *)malloc(sizeof(*s1) * (right - left + 1))))
		return (NULL);
	while (left < right)
		str[begin++] = s1[left++];
	str[begin] = '\0';
	return (str);
}
