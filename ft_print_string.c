#include "ft_printf.h"
// смотрим точность
static char	*ft_procprecision(t_struct *p, char *space, char *s)
{
	if (p->precision == DISABLED ||
						(p->precision != 0 && p->precision >= (int)ft_strlen(s)))
		return (s); // если нет . или точность больше или равна длине аргумента то вернем сразу аргумент
	if (!(space = malloc(sizeof(char) * (p->precision + 1))))
		return (NULL);
	ft_strncpy(space, s, p->precision); // копируем в спейс на результат до определенной точности
	space[p->precision] = '\0';
	return (space);
}
// смотрим ширину
static char	*ft_procwidth(t_struct *p, char *space, char *s)
{
	int	slen;

	slen = ft_strlen(s); // считаем длину результата
	if (p->width <= slen) // если ширина меньше длины результата
		return (s);
	if (!(space = ft_fillspace(p->width, p->padding))) // заполняем спейс падингом
		return (NULL);
	if (p->minus == ENABLED) // если минус то копируем в спейс
		ft_strncpy(space, s, slen);
	else
		ft_strncpy(&space[p->width - slen], s, slen);
	return (space);
}

int	ft_print_str(t_struct *p, char *res)
{
	t_space	*space;
	int		flag;

	flag = DISABLED;
	if (res == NULL)
	{
		res = ft_strndup("(null)", 6); // случай для %s 0 %s NULL
		flag = ENABLED;
	}
	space = ft_prepspace();
	if ((res = ft_procprecision(p, space->precision, res)) == NULL
			|| (res = ft_procwidth(p, space->width, res)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	p->nbyte += ft_putstrn(res, ft_strlen(res)); // печатаем результат
	ft_freespace(space);
	if (flag == ENABLED)
		free(res); // чистим рез если малочили для NULL
	return (0);
}
