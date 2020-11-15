/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:13:50 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/14 14:33:56 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhite(const char *str)
{
	if (*str == 32 || (*str >= 9 && *str <= 13))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (iswhite(str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
