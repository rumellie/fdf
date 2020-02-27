/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:37:18 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 05:41:01 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(int key, t_fdf **data)
{
	if (key == 126)
		(*data)->y_shift -= 10;
	if (key == 125)
		(*data)->y_shift += 10;
	if (key == 123)
		(*data)->x_shift -= 10;
	if (key == 124)
		(*data)->x_shift += 10;
	if (key == 84)
		(*data)->x_angle -= 0.1;
	if (key == 91)
		(*data)->x_angle += 0.1;
	if (key == 86)
		(*data)->y_angle -= 0.1;
	if (key == 88)
		(*data)->y_angle += 0.1;
	if (key == 83)
		(*data)->z_angle -= 0.1;
	if (key == 85)
		(*data)->z_angle += 0.1;
}

int		ft_deal_key(int key, t_fdf *data)
{
	ft_move(key, &data);
	if (key == 75)
	{
		ft_init_data(data);
		data->iso = (data->iso == 1 ? 0 : 1);
	}
	if (key == 69)
		if (data->zoom < 200)
			data->zoom += 5;
	if (key == 78)
		if (data->zoom > 5)
			data->zoom -= 5;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data);
	return (0);
}
