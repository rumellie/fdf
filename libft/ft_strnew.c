/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:16:22 by mellie            #+#    #+#             */
/*   Updated: 2019/09/28 06:38:34 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if ((size + 1) == 0)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size)
	{
		s[size] = '\0';
		size--;
	}
	s[0] = '\0';
	return (s);
}
