#include "ft_printf.h"
// инит спейса
t_space	*ft_prepspace(void)
{
	t_space	*sp;

	sp = malloc(sizeof(t_space));
	sp->precision = NULL;
	sp->width = NULL;
	return (sp);
}
// заполняем спейс
char	*ft_fillspace(int size, char padding)
{
	char	*space;

	if (!(space = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(space, padding, size);// через мемсет заполняем все паддингом
	space[size] = '\0';
	return (space);
}
// чистим спейс
void	ft_freespace(t_space *space)
{
	if (space->precision)
		free(space->precision);
	if (space->width)
		free(space->width);
	free(space);
}
