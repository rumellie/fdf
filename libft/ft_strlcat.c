/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:40:38 by mellie            #+#    #+#             */
/*   Updated: 2019/09/20 16:38:15 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t bs;
	size_t i;
	size_t dlen;

	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (ft_strlen(src) + size);
	bs = size - dlen;
	i = 0;
	while (i < bs && src[i])
	{
		if (i == bs - 1)
			break ;
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (size + (ft_strlen(src) - bs));
}
