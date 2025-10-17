/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:44 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 16:31:14 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static int	open_file(t_cub3d *cub3d, char *map)
{
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		error(strerror(errno));
		ft_free(cub3d);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	filler(t_cub3d *cub3d, char *line, int fd, size_t row)
{
	if (map_validity_checker(cub3d, line) == -1)
	{
		close(fd);
		free(line);
		return (-1);
	}
	cub3d->map.temp[row] = ft_strdup(line);
	if (cub3d->map.temp[row][ft_strlen(line) - 1] == '\n')
		cub3d->map.temp[row][ft_strlen(line) - 1] = '\0';
	return (0);
}

static int	fill_map(t_cub3d *cub3d, char *map)
{
	char	*line;
	int		fd;
	size_t	row;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (error(strerror(errno)), -1);
	row = 0;
	while (row++ < cub3d->map.start_row)
		free(get_next_line(fd));
	line = get_next_line(fd);
	row = 0;
	while (line)
	{
		if (filler(cub3d, line, fd, row))
			return (-1);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	close(fd);
	if (set_map(cub3d) == -1 || check_empty(cub3d))
		return (-1);
	return (0);
}

static int	read_loop(t_cub3d *cub3d, char **line, int fd)
{
	if (!check_init(cub3d))
	{
		if (init_textures(cub3d, line, fd) == -1)
		{
			close(fd);
			return (-1);
		}
	}
	if (check_init(cub3d))
	{
		if (init_map(cub3d, (*line)) == -1)
		{
			close(fd);
			return (-1);
		}
	}
	return (0);
}

int	read_file(t_cub3d *cub3d, char *map)
{
	int			fd;
	char		*line;

	fd = open_file(cub3d, map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (read_loop(cub3d, &line, fd) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cub3d->map.temp = ft_calloc(cub3d->map.row + 1, sizeof(char *));
	if (!cub3d->map.temp)
		return (error(strerror(errno)), -1);
	if (fill_map(cub3d, map) == -1)
		return (-1);
	return (0);
}
