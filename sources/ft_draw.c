/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 04:59:23 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:24:17 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_max(float a, float b)
{
	return (a > b ? a : b);
}

float		ft_mod(float num)
{
	return (num < 0 ? -num : num);
}

void		ft_bres(float x, float y, int goriz, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	z_step;
	int		max;
	t_line	*line;

	line = ft_init_line(x, y, goriz, data);
	ft_transform(line, data);
	x_step = line->x1 - line->x;
	y_step = line->y1 - line->y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	z_step = line->delta_z / max;
	while ((int)(line->x - line->x1) || (int)(line->y - line->y1))
	{
		data->color = ft_get_color(data, line->z_cc);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->x, line->y, \
				data->color);
		line->x += x_step;
		line->y += y_step;
		line->z_cc += z_step;
	}
	free(line);
}

void		ft_draw(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bres(x, y, 1, data);
			if (y < data->height - 1)
				ft_bres(x, y, 0, data);
			x++;
		}
		y++;
	}
	ft_print_menu(data);
}
