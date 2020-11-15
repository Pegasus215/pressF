/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:34:07 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 16:15:27 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prechar(va_list ap, t_struct *p)
{
	char	c;

	c = (char)va_arg(ap, unsigned int);
	return (ft_print_char(p, c));
}

int	ft_prestr(va_list ap, t_struct *p)
{
	char	*str;

	str = va_arg(ap, char *);
	return (ft_print_str(p, str));
}

int	ft_preint(va_list ap, t_struct *p)
{
	char	*res;

	res = ft_itoa((int)va_arg(ap, int));
	if (res == NULL)
		return (ERROR);
	return (ft_print_int(p, res));
}

int	ft_preunsigned(va_list ap, t_struct *p)
{
	char	*res;

	res = ft_uitoa((unsigned int)va_arg(ap, int));
	if (res == NULL)
		return (ERROR);
	return (ft_print_unsigned(p, res));
}

int	ft_prehexa(va_list ap, t_struct *p, char *base)
{
	char	*res;

	res = ft_itoa_base((int)va_arg(ap, int), base);
	if (res == NULL)
		return (ERROR);
	return (ft_print_hexa(p, res));
}
