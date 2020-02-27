/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:00:50 by mellie            #+#    #+#             */
/*   Updated: 2019/09/22 22:04:11 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
			tmp[i] = f(s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
