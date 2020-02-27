/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:58:04 by mellie            #+#    #+#             */
/*   Updated: 2019/09/24 21:31:46 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	start;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (s[i] && i > start && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i--;
	if (!(res = ft_strnew(i + 1 - start)))
		return (NULL);
	j = 0;
	while (start < i + 1)
	{
		res[j] = s[start];
		j++;
		start++;
	}
	return (res);
}
