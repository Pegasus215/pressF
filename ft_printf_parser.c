/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:32:32 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/14 17:25:17 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// Смотрим Флаги
static void	ft_parse_flags(char **format, t_struct *p)
{
	while (ft_set(**format, FLAG))
	{
		**format == '-' ? p->minus = ENABLED : SKIP;
		**format == '0' ? p->zero = ENABLED : SKIP;
		(*format)++;
	}
}
// Смотрим ширину
static void	ft_parse_width(char **format, va_list ap, t_struct *p)
{
	char	*temp;

	if (!(**format == '*' || ft_set(**format, DIGIT)))
		return ;
	if (**format == '*') // если встречаем * берем аргумент
	{
		p->width = va_arg(ap, int);
		(*format)++;
	}
	else
	{
		temp = ft_strndup(*format, ft_strlen(*format)); // дюпаем формат в темп
		p->width = ft_atoi(temp); // ишем цифру после флага и записываем в ширину
		free(temp); // освобождаем темп
		while (ft_set(**format, DIGIT))
			(*format)++;
	}
	if (p->width < 0)
	{
		p->minus = ENABLED;// если ширина отрицательная врубаем минус
		p->width = -p->width;
	}
}

static void	ft_parse_precision(char **format, va_list ap, t_struct *p)
{
	char	*temp;
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*') // если встречаем * берем аргумент
	{
		p->precision = va_arg(ap, int);
		(*format)++;
	}
	else if (ft_set(**format, DIGIT))
	{
		temp = ft_strndup(*format, ft_strlen(*format)); // дюпаем формат после . в темп
		p->precision = ft_atoi(temp); // записываем в точность с помощью атои
		free(temp);
		while (ft_set(**format, DIGIT))//скипаем все число
			(*format)++;
	}
	else
		p->precision = 0;
	if (p->precision < 0)
		p->precision = DISABLED;// вырубаем отрицательную точность
}

int	ft_parse(char **format, va_list ap, t_struct *p)
{
	if (**format == '\0')
		return (ERROR);
	ft_parse_flags(format, p);// смотрим флаг
	ft_parse_width(format, ap, p);// смотрим ширину
	ft_parse_precision(format, ap, p);// смотрим точность
	if (ft_set(**format, CONV) == 0)// если не находим тип то ретурним -1
		return (ERROR);
	return (0);
}
