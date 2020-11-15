/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:33:28 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 16:16:56 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_space	*ft_prepspace(void)
{
	t_space	*sp;

	sp = malloc(sizeof(t_space));
	sp->precision = NULL;
	sp->width = NULL;
	return (sp);
}

char	*ft_fillspace(int size, char padding)
{
	char	*space;

	if (!(space = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(space, padding, size);
	space[size] = '\0';
	return (space);
}

void	ft_freespace(t_space *space)
{
	if (space->precision)
		free(space->precision);
	if (space->width)
		free(space->width);
	free(space);
}
