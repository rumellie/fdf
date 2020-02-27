/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:37:30 by mellie            #+#    #+#             */
/*   Updated: 2020/01/16 16:53:17 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*check_tail(char **line, char *tail)
{
	char	*p_n;

	p_n = NULL;
	if (tail)
		if ((p_n = ft_strchr(tail, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(tail);
			ft_strcpy(tail, ++p_n);
		}
		else
		{
			*line = ft_strdup(tail);
			ft_strclr(tail);
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int			get_line(const int fd, char **line, char **tail)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*p_n;
	char	*tmp;

	p_n = check_tail(line, *tail);
	if (p_n)
		return (1);
	while ((!p_n && (ret = read(fd, buf, BUFF_SIZE))))
	{
		buf[ret] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			free(*tail);
			*tail = ft_strdup(p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || ret < 0)
			return (-1);
		free(tmp);
	}
	return (ret || ft_strlen(*line)) ? 1 : 0;
}

t_gnl		*new_gnl_list(const int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->tail = NULL;
	new->next = NULL;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (head == NULL)
		head = new_gnl_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_gnl_list(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->tail));
}
