#include "ft_printf.h"
// смотрим ширину для чара
static char	*ft_procwidth(t_struct *p, char *space)
{
	p->width--;
	if (p->width < 1)
		return ("");
	if (!(space = ft_fillspace(p->width, p->padding))) // заполняем спейс падингом
		return (NULL);
	return (space);
}
// печатаем чар
int		ft_print_char(t_struct *p, char c)
{
	char	*res;
	int		flag;
	t_space	*space; // структура для спейса

	flag = DISABLED;
	if (p->precision > 0)
		return (UNDEFINED); // точность для чара?
	space = ft_prepspace(); // инитим спейс
	if ((res = ft_procwidth(p, space->width)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	if (p->minus == ENABLED)
		p->nbyte += ft_putchar(c) + ft_putstr(res);
	else
		p->nbyte += ft_putstr(res) + ft_putchar(c);
	free(space);
	return (0);
}
