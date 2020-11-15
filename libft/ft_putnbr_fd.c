/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:27:52 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:38 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((n * (-1)), fd);
	}
	else
	{
		if ((n / 10) > 0)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}
