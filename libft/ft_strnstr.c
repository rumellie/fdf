/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:30:53 by mellie            #+#    #+#             */
/*   Updated: 2019/09/16 23:33:04 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	int i;
	int j;

	i = 0;
	if (n[i] == '\0')
		return ((char*)&h[i]);
	while ((h[i] != '\0') && (i < (int)len))
	{
		j = 0;
		while ((h[i + j] == n[j]) && ((i + j) < (int)len))
		{
			if (n[j + 1] == '\0')
				return ((char*)&h[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
