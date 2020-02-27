/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:01:53 by mellie            #+#    #+#             */
/*   Updated: 2019/09/21 00:23:54 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	else
		return (0);
}

static int	ft_issign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	long long	i;
	int			s;
	int			res;

	i = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		s = ft_issign(str[i]);
		i++;
	}
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && i < 20)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (i == 20 && s == -1)
		return (0);
	else if (i == 20 && s == 1)
		return (-1);
	else
		return (s * res);
}
