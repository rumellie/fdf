/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:24:43 by mellie            #+#    #+#             */
/*   Updated: 2019/09/19 15:54:48 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	const unsigned char		*ts;
	unsigned char			*buf;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	ts = (const unsigned char *)src;
	while (i < len && &src[i] != dst)
		i++;
	if (i != len)
	{
		i = 0;
		buf = (unsigned char *)malloc(len);
		while (i < len)
		{
			buf[i] = ts[i];
			i++;
		}
		return (ft_memcpy(dst, buf, len));
	}
	else
		return (ft_memcpy(dst, ts, len));
}
