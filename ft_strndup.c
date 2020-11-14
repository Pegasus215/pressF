
#include "libft.h"

char	*ft_strndup(const char *s1, int size)
{
	char	*temp;
	int		i;
	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[size] = 0;
	return (temp);
}
