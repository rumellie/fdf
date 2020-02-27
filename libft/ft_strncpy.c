/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:50:12 by mellie            #+#    #+#             */
/*   Updated: 2019/09/19 19:30:47 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
		{
			dst[i] = src[i];
			i++;
			break ;
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (i < len)
		ft_bzero(&dst[i], (len - i));
	return (dst);
}
