/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:06:07 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:30 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *ltl, size_t len)
{
	unsigned char	*bp;
	unsigned char	*lp;
	size_t			i;

	bp = (unsigned char *)big;
	lp = (unsigned char *)ltl;
	i = 0;
	if (ft_strlen(ltl) == 0)
		return ((char *)bp);
	while (i < len)
	{
		if ((ft_strncmp((char *)&bp[i], ltl, ft_strlen(ltl)) == 0))
		{
			if ((i + ft_strlen(ltl)) > len)
				return (NULL);
			return ((char *)&bp[i]);
		}
		i++;
	}
	return (NULL);
}
