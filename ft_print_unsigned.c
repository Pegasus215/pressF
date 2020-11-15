/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:18:59 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:31:26 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_procprecision(t_struct *p, char *space, char *s)
{
	int	slen;

	slen = ft_strlen(s);
	if (s[0] == '0' && p->precision == 0)
		s = "";
	if (p->precision <= slen)
		return (s);
	if (!(space = ft_fillspace(p->precision, '0')))
		return (NULL);
	ft_strcpy(&space[p->precision - slen], s);
	return (space);
}

static char	*ft_procwidth(t_struct *p, char *space, char *s)
{
	int	slen;

	slen = ft_strlen(s);
	if (s[0] == '\0' && p->width < slen)
		return (s);
	if (p->zero == ENABLED &&
					p->precision == DISABLED && p->minus == DISABLED)
		p->padding = '0';
	if (p->width < slen)
		p->width = slen;
	if (p->sign && p->width == slen)
		p->width++;
	if (!(space = ft_fillspace(p->width, p->padding)))
		return (NULL);
	if (p->minus == ENABLED && p->sign)
		ft_strncpy(space + 1, s, slen);
	else if (p->minus == ENABLED)
		ft_strncpy(space, s, slen);
	else
		ft_strncpy(&space[p->width - slen], s, slen);
	return (ft_procsign(p, space, slen));
}

int			ft_print_unsigned(t_struct *p, char *res)
{
	t_space	*space;

	space = ft_prepspace();
	res = ft_prepsign(p, res);
	if ((res = ft_procprecision(p, space->precision, res)) == NULL
			|| (res = ft_procwidth(p, space->width, res)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	p->nbyte += ft_putstrn(res, ft_strlen(res));
	ft_freespace(space);
	return (0);
}
