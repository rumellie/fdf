/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:21:38 by mellie            #+#    #+#             */
/*   Updated: 2019/09/19 13:22:53 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
		if (*((unsigned char*)(src + i)) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
