/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:09:03 by mellie            #+#    #+#             */
/*   Updated: 2019/09/22 22:25:50 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	size_t	i;

	if (s && *s && f)
	{
		i = 0;
		if (!(tmp = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			tmp[i] = f(i, s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
