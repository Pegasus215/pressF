/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:44:38 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:32:39 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long int n, const char *base)
{
	long long		div;
	unsigned int	len;
	long long		base_len;
	char			*res;

	div = n;
	len = (n == 0) ? 1 : 0;
	base_len = (long long)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (!(res = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = base[(n % base_len)];
		n = n / base_len;
	}
	return (res);
}
