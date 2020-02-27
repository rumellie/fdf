/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:59:42 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:51:51 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_line *line, t_fdf *data)
{
	line->x *= data->zoom;
	line->y *= data->zoom;
	line->x1 *= data->zoom;
	line->y1 *= data->zoom;
	line->z *= data->zoom / 3;
	line->z1 *= data->zoom / 3;
}

void	ft_rotate(t_line *line, t_fdf *data)
{
	ft_rotate_x(&(line->y), &(line->z), data);
	ft_rotate_y(&(line->x), &(line->z), data);
	ft_rotate_z(&(line->x), &(line->y), data);
	ft_rotate_x(&(line->y1), &(line->z1), data);
	ft_rotate_y(&(line->x1), &(line->z1), data);
	ft_rotate_z(&(line->x1), &(line->y1), data);
}

void	ft_shift(t_line *line, t_fdf *data)
{
	line->x += data->x_shift;
	line->y += data->y_shift;
	line->x1 += data->x_shift;
	line->y1 += data->y_shift;
	line->z += 1200;
	line->z1 += 1200;
}

int		ft_project(t_line *line, t_fdf *data)
{
	if (data->iso)
	{
		ft_isometric(&(line->x), &(line->y), line->z);
		ft_isometric(&(line->x1), &(line->y1), line->z1);
	}
	else
	{
		if (ft_perspect(&(line->x), &(line->y), line->z))
			return (0);
		if (ft_perspect(&(line->x1), &(line->y1), line->z1))
			return (0);
	}
	return (0);
}

void	ft_transform(t_line *line, t_fdf *data)
{
	ft_zoom(line, data);
	ft_rotate(line, data);
	ft_shift(line, data);
	ft_project(line, data);
}
