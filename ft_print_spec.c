/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:12:09 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:40:03 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_procwidth(t_struct *p, char *space, char s)
{
	if (p->width < 2)
		p->width = 1;
	if (p->zero == ENABLED && p->minus == DISABLED)
		p->padding = '0';
	if (!(space = ft_fillspace(p->width, p->padding)))
		return (NULL);
	if (p->minus == ENABLED)
		space[0] = s;
	else
		space[p->width - 1] = s;
	return (space);
}

int			ft_print_spec(t_struct *p)
{
	t_space	*space;
	char	*res;
	char	c;

	c = '%';
	space = ft_prepspace();
	if ((res = ft_procwidth(p, space->width, c)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	p->nbyte += ft_putstrn(res, ft_strlen(res));
	ft_freespace(space);
	return (0);
}
