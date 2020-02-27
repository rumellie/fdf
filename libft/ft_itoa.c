/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:49:59 by mellie            #+#    #+#             */
/*   Updated: 2019/09/21 17:01:04 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		t;

	t = 0;
	i = ft_nblen(n);
	if (!(s = (char*)malloc(ft_nblen(n) + 1)))
		return (NULL);
	if (n == -2147483648)
	{
		n = n + 1;
		t = 1;
	}
	if (n < 0)
	{
		s[0] = '-';
		n = n * (-1);
	}
	s[i] = '\0';
	s[--i] = ((n % 10) + t + '0');
	while (n /= 10)
		s[--i] = ((n % 10) + '0');
	return (s);
}