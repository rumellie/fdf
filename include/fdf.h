/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 06:03:59 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:52:28 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct		s_fdf {
	int				height;
	int				width;
	int				**z_matrix;
	int				min_z;
	int				max_z;
	int				zoom;
	int				color;
	int				x_shift;
	int				y_shift;
	float			x_angle;
	float			y_angle;
	float			z_angle;
	int				iso;
	int				start_color;
	int				end_color;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_fdf;

typedef struct		s_line {
	float			x;
	float			y;
	float			x1;
	float			y1;
	float			z;
	float			z1;
	int				start_x;
	int				start_y;
	float			delta_z;
	float			z_cc;
}					t_line;

void				ft_read_file(char *file_name, t_fdf *data);
void				ft_bres(float x, float y, int goriz, t_fdf *data);
void				ft_draw(t_fdf *data);
void				ft_isometric(float *x, float *y, int z);
int					ft_perspect(float *x, float *y, int z);
int					ft_error(int err_code);
int					ft_deal_key(int key, t_fdf *data);
int					ft_countword(char *s, char c);
void				ft_rotate_x(float *y, float *z, t_fdf *data);
void				ft_rotate_y(float *x, float *z, t_fdf *data);
void				ft_rotate_z(float *x, float *y, t_fdf *data);
int					ft_get_color(t_fdf *data, float z);
int					ft_get_light(int start, int end, double percentage);
double				ft_percent(int start, int end, float current);
void				ft_get_minmaxz(t_fdf *data);
void				ft_init_data(t_fdf *data);
void				ft_print_menu(t_fdf *data);
void				ft_move(int key, t_fdf **data);
t_line				*ft_init_line(float x, float y, int goriz, t_fdf *data);
void				ft_zoom(t_line *line, t_fdf *data);
void				ft_rotate(t_line *line, t_fdf *data);
void				ft_shift(t_line *line, t_fdf *data);
int					ft_project(t_line *line, t_fdf *data);
void				ft_transform(t_line *line, t_fdf *data);
float				ft_mod(float num);
float				ft_max(float a, float b);
#endif
