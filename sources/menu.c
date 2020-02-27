/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:43:14 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:28:40 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, 0xff02ff, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, 0xff02ff, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, 0xff02ff, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, 0xff02ff, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, 0xff02ff, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, 0xff02ff, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, 0xff02ff, "Z-Axis - 1/3");
	mlx_string_put(mlx, win, 15, y += 30, 0xff02ff, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, 0xff02ff, "ISO: / Key");
}
