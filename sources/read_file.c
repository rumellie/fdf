/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:44:06 by mellie            #+#    #+#             */
/*   Updated: 2020/02/24 06:27:42 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error(1);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	free(line);
	return (height);
}

static int	ft_get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	width = 0;
	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error(1);
	get_next_line(fd, &line);
	width = ft_countword(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	close(fd);
	free(line);
	return (width);
}

static void	ft_fill_matr(int *z_line, char *line)
{
	int		i;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	i = 0;
	while (tmp[i])
	{
		z_line[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void		ft_read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_fill_matr(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	data->z_matrix[i] = NULL;
}
