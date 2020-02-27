/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:41:36 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:39:19 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		ft_read_file(argv[1], data);
		ft_init_data(data);
		data->iso = 1;
		ft_get_minmaxz(data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		ft_draw(data);
		mlx_hook(data->win_ptr, 2, data->width, ft_deal_key, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else
		ft_error(0);
	return (0);
}
