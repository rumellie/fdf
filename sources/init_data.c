/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:33:38 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 05:36:44 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_data(t_fdf *data)
{
	data->zoom = 20;
	data->x_shift = 2000;
	data->y_shift = 1500;
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->color = 0xffccff;
	data->start_color = 0xffccff;
	data->end_color = 0xcc00cc;
}

t_line		*ft_init_line(float x, float y, int goriz, t_fdf *data)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->x = x;
	line->y = y;
	if (goriz == 1)
	{
		line->x1 = x + 1;
		line->y1 = y;
	}
	else
	{
		line->x1 = x;
		line->y1 = y + 1;
	}
	line->z = data->z_matrix[(int)y][(int)x];
	line->z1 = data->z_matrix[(int)line->y1][(int)line->x1];
	line->start_x = x;
	line->start_y = y;
	line->delta_z = line->z1 - line->z;
	line->z_cc = line->z;
	return (line);
}
