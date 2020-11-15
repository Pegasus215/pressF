/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:24:40 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:43:33 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_procprecision(t_struct *p, char *space, char *s)
{
	if (p->precision == DISABLED || (p->precision != 0 &&
								p->precision >= (int)ft_strlen(s)))
		return (s);
	if (!(space = malloc(sizeof(char) * (p->precision + 1))))
		return (NULL);
	ft_strncpy(space, s, p->precision);
	space[p->precision] = '\0';
	return (space);
}

static char		*ft_procwidth(t_struct *p, char *space, char *s)
{
	int		slen;

	slen = ft_strlen(s);
	if (p->width <= slen)
		return (s);
	if (!(space = ft_fillspace(p->width, p->padding)))
		return (NULL);
	if (p->minus == ENABLED)
		ft_strncpy(space, s, slen);
	else
		ft_strncpy(&space[p->width - slen], s, slen);
	return (space);
}

int				ft_print_str(t_struct *p, char *res)
{
	t_space		*space;
	int			flag;

	flag = DISABLED;
	if (res == NULL)
	{
		res = ft_strndup("(null)", 6);
		flag = ENABLED;
	}
	space = ft_prepspace();
	if ((res = ft_procprecision(p, space->precision, res)) == NULL
			|| (res = ft_procwidth(p, space->width, res)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	p->nbyte += ft_putstrn(res, ft_strlen(res));
	ft_freespace(space);
	if (flag == ENABLED)
		free(res);
	return (0);
}
