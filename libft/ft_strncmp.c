/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:22:04 by mellie            #+#    #+#             */
/*   Updated: 2019/09/17 14:07:52 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char *ts1;
	const unsigned char *ts2;

	i = 0;
	ts1 = (const unsigned char *)s1;
	ts2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ts1[i] != '\0' && ts2[i] != '\0' && ts1[i] == ts2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return (ts1[i] - ts2[i]);
}
