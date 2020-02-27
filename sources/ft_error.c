/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:18:35 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:41:07 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int err_code)
{
	if (err_code == 1)
		write(1, "File is not valid.\n", 19);
	else if (err_code == 0)
		ft_putstr_fd("usage: ./fillit [Input_file]\n", 2);
	exit(err_code);
}
