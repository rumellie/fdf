/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:09:00 by mellie            #+#    #+#             */
/*   Updated: 2019/09/20 23:26:30 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char *ts1;
	const unsigned char	*ts2;

	i = 0;
	ts1 = (const unsigned char *)s1;
	ts2 = (const unsigned char *)s2;
	while (ts1[i] != '\0' && ts2[i] != '\0' && ts1[i] == ts2[i])
		i++;
	return (ts1[i] - ts2[i]);
}
