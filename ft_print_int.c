#include "ft_printf.h"
// смотрим точность
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
// смотрим ширину
static char	*ft_procwidth(t_struct *p, char *space, char *s)
{
	int	slen;

	slen = ft_strlen(s);
	if (s[0] == '\0' && p->width < slen)
		return (s);
	if (p->zero == ENABLED &&
					p->precision == DISABLED && p->minus == DISABLED)
		p->padding = '0'; // если есть флаг зеро и нет -. то заменяем паддинг на 0
	if (p->width < slen)
		p->width = slen; // если ширина меньше длины результата то делаем ее равной длине результата
	if (p->sign && p->width == slen) // если есть знак минус то увеличиваем ширину на 1
		p->width++;
	if (!(space = ft_fillspace(p->width, p->padding))) // заполняем спейс 0
		return (NULL);
	if (p->minus == ENABLED && p->sign) // если минус и отрицательное то копируем +1
		ft_strncpy(space + 1, s, slen);
	else if (p->minus == ENABLED)
		ft_strncpy(space, s, slen); // копируем в конец
	else
		ft_strncpy(&space[p->width - slen], s, slen); // копируем в начало
	return (ft_procsign(p, space, slen));
}
// печатаем инт
int		ft_print_int(t_struct *p, char *res)
{
	t_space	*space;

	space = ft_prepspace();// инит спейса
	res = ft_prepsign(p, res); // смотрим знак -
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
