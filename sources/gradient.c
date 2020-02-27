/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:19:40 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 05:32:40 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_get_minmaxz(t_fdf *data)
{
	int		i;
	int		j;

	i = 0;
	data->max_z = 0;
	data->min_z = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] > data->max_z)
				data->max_z = data->z_matrix[i][j];
			if (data->z_matrix[i][j] < data->min_z)
				data->min_z = data->z_matrix[i][j];
			j++;
		}
		i++;
	}
}

double		ft_percent(int start, int end, float current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			ft_get_color(t_fdf *data, float z)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	percentage = ft_percent(data->min_z, data->max_z, z);
	red = ft_get_light((data->start_color >> 16) & 0xFF, \
			(data->end_color >> 16) & 0xFF, percentage);
	green = ft_get_light((data->start_color >> 8) & 0xFF, \
			(data->end_color >> 8) & 0xFF, percentage);
	blue = ft_get_light(data->start_color & 0xFF, data->end_color & 0xFF, \
			percentage);
	return ((red << 16) | (green << 8) | blue);
}
