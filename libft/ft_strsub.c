/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:54:17 by mellie            #+#    #+#             */
/*   Updated: 2019/09/22 23:55:42 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s || !(substr = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}
