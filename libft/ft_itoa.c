/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:34:39 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:51 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else if (n > 0)
		return (n);
	return (0);
}

static int	ft_intlen(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*arr;
	int		dl;

	dl = ft_intlen(n);
	if (!(arr = (char *)malloc(sizeof(char) * (dl + 1))))
		return (NULL);
	arr[dl--] = '\0';
	if (n == 0)
		arr[0] = '0';
	if (n == 0)
		return (arr);
	if (n < 0)
		arr[0] = '-';
	while (ft_abs(n))
	{
		arr[dl] = '0' + ft_abs((n % 10));
		n /= 10;
		dl--;
	}
	return (arr);
}
