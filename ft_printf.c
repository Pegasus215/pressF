#include "ft_printf.h"
// Смотрим тип
static int	ft_condition(char *format, va_list ap, t_struct *p)
{
	if (*format == 'c')
		return (ft_prechar(ap, p));
	else if (*format == 's')
		return (ft_prestr(ap, p));
	else if (*format == 'd' || *format == 'i')
		return (ft_preint(ap, p));
	else
		return (ERROR);
}
// Инит структуры
static void	ft_prep(t_struct *p)
{
	p->width = DISABLED;
	p->precision = DISABLED;
	p->zero = DISABLED;
	p->minus = DISABLED;
	p->padding = ' ';
	p->sign = '\0';
}

// Здесь происходит поиск % и вызов парсера
static int	ft_format(char *format, va_list ap)
{
	t_struct p;

	p.nbyte = 0;
	if (format == 0)
		return (ERROR);
	while (*format)
	{
		while (*format != '%' && format)
		{
			p.nbyte += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			ft_prep(&p); // Инит структуры
			if (ft_parse(&format, ap, &p) == ERROR)
				return (ERROR);
			if (ft_condition(format, ap, &p) == ERROR)
				return (ERROR);
			format++;
		}
	}
	return (p.nbyte);
}

//основная функция
int		ft_printf(const char *format, ...)
{
	va_list	ap; // Лист аргументов
	int		nbyte; // Кол-во записанных байт

	va_start(ap, format);
	if ((nbyte = ft_format((char *)format, ap)) == ERROR)
		return (ERROR);
	va_end(ap);
	return (nbyte);
}
