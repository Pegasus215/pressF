#include "ft_printf.h"

char	*ft_prepsign(t_struct *p, char *s)
{
	if (s[0] == '-')
	{
		p->sign = '-';
		s++;
	}
	return (s);
}

char	*ft_procsign(t_struct *p, char *space, int slen)
{
	if (p->sign == '\0')
		return (space);
	if ((p->zero == ENABLED && p->precision == DISABLED)
				|| p->minus == ENABLED)
		space[0] = p->sign;
	else
		space[p->width - slen - 1] = p->sign;
	return (space);
}
