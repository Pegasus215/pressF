/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:30:56 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:34 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (NULL == s1 && NULL == s2)
		return (NULL);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[j] != '\0')
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}
