/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:50:19 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:43:44 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_isometric(float *x, float *y, int z)
{
	float	ty;
	float	tx;

	ty = *y;
	tx = *x;
	*x = (tx - ty) * cos(0.523599);
	*y = (tx + ty) * sin(0.523599) - z;
}

int			ft_perspect(float *x, float *y, int z)
{
	float	ty;
	float	tx;

	ty = (*y - 1500) * 3.5f;
	tx = (*x - 2000) * 3.5f;
	if (z <= 250)
		return (1);
	*x = (tx * 250 / z) + 500;
	*y = (ty * 250 / z) + 500;
	return (0);
}

void		ft_rotate_x(float *y, float *z, t_fdf *data)
{
	float	ty;
	float	tz;

	ty = *y;
	tz = *z;
	*y = ((ty - (data->height) * data->zoom / 2) * cos(data->x_angle) + \
			(tz) * sin(data->x_angle));
	*z = (-(ty - (data->height) * data->zoom / 2) * sin(data->x_angle) + \
			(tz) * cos(data->x_angle));
}

void		ft_rotate_y(float *x, float *z, t_fdf *data)
{
	float tx;
	float tz;

	tx = *x;
	tz = *z;
	*x = ((tx - (data->width) * data->zoom / 2) * cos(data->y_angle) + \
			(tz) * sin(data->y_angle));
	*z = (-(tx - (data->width) * data->zoom / 2) * sin(data->y_angle) + \
			(tz) * cos(data->y_angle));
}

void		ft_rotate_z(float *x, float *y, t_fdf *data)
{
	float tx;
	float ty;

	tx = *x;
	ty = *y;
	*x = ((tx) * cos(data->z_angle) - (ty) * sin(data->z_angle));
	*y = ((tx) * sin(data->z_angle) + (ty) * cos(data->z_angle));
}
