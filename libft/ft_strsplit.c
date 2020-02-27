/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:13:39 by mellie            #+#    #+#             */
/*   Updated: 2019/09/26 21:15:50 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		*ft_isword(char const *s, size_t *ind, char c)
{
	size_t		i;
	size_t		start;
	size_t		len;
	char		*tmp;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	start = i;
	while (s[i] != c && s[i])
		i++;
	len = i - start;
	if (!(tmp = ft_strsub(s, (unsigned int)start, len)))
		return (NULL);
	*ind = *ind + i;
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		j;
	size_t		cw;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	cw = ft_countword(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (cw + 1))))
		return (NULL);
	while (s[i] && j < cw)
	{
		if (!(res[j] = ft_isword(&s[i], &i, c)))
		{
			while (j)
				free(res[--j]);
			free(res);
			return (NULL);
		}
		j++;
	}
	res[j] = NULL;
	return (res);
}
