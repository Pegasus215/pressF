/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:12:11 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/09 16:49:37 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char		*ft_malloc_word(char **split, char const *s, char c, int words)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
	{
		while (words-- > 0)
			free(split[words]);
		free(split);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = ft_malloc_word(split, s, c, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
