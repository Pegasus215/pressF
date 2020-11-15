/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:32:32 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:31:13 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_flags(char **format, t_struct *p)
{
	while (ft_set(**format, FLAG))
	{
		**format == '-' ? p->minus = ENABLED : SKIP;
		**format == '0' ? p->zero = ENABLED : SKIP;
		(*format)++;
	}
}

static void	ft_parse_width(char **format, va_list ap, t_struct *p)
{
	char	*temp;

	if (!(**format == '*' || ft_set(**format, DIGIT)))
		return ;
	if (**format == '*')
	{
		p->width = va_arg(ap, int);
		(*format)++;
	}
	else
	{
		temp = ft_strndup(*format, ft_strlen(*format));
		p->width = ft_atoi(temp);
		free(temp);
		while (ft_set(**format, DIGIT))
			(*format)++;
	}
	if (p->width < 0)
	{
		p->minus = ENABLED;
		p->width = -p->width;
	}
}

static void	ft_parse_precision(char **format, va_list ap, t_struct *p)
{
	char	*temp;

	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		p->precision = va_arg(ap, int);
		(*format)++;
	}
	else if (ft_set(**format, DIGIT))
	{
		temp = ft_strndup(*format, ft_strlen(*format));
		p->precision = ft_atoi(temp);
		free(temp);
		while (ft_set(**format, DIGIT))
			(*format)++;
	}
	else
		p->precision = 0;
	if (p->precision < 0)
		p->precision = DISABLED;
}

int			ft_parse(char **format, va_list ap, t_struct *p)
{
	if (**format == '\0')
		return (ERROR);
	ft_parse_flags(format, p);
	ft_parse_width(format, ap, p);
	ft_parse_precision(format, ap, p);
	if (ft_set(**format, CONV) == 0)
		return (ERROR);
	return (0);
}
