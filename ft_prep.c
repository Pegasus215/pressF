/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:34:07 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/14 17:18:38 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//подготавливаем аргумент для принта чара
int	ft_prechar(va_list ap, t_struct *p)
{
	char	c;

	c = (char)va_arg(ap, unsigned int);
	return (ft_print_char(p, c));
}
//подготавливаем аргумент для принта стринги
int	ft_prestr(va_list ap, t_struct *p)
{
	char	*str;

	str = va_arg(ap, char *);
	return (ft_print_str(p, str));
}
//подготавливаем аргумент для принта инта
int	ft_preint(va_list ap, t_struct *p)
{
	char	*res;

	res = ft_itoa((int)va_arg(ap, int));//переводим число в чар
	if (res == NULL)
		return (ERROR);
	return (ft_print_int(p, res));
}
//безнаковые
int	ft_preunsigned(va_list ap, t_struct *p)
{
	char	*res;

	res = ft_uitoa((unsigned int)va_arg(ap, int));
	if (res == NULL)
		return (ERROR);
	return (ft_print_unsigned(p, res));
}
//хекс
int	ft_prehexa(va_list ap, t_struct *p, char *base)
{
	char	*res;

	res = ft_itoa_base((int)va_arg(ap, int), base);
	if (res == NULL)
		return (ERROR);
	return (ft_print_hexa(p, res));
}
