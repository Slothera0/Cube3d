/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:08:27 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/09/17 23:56:08 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <string.h>
#include <errno.h>

static void	fill_character(t_cub3d *cub3d, size_t i, size_t j, size_t k)
{
	if (cub3d->map.temp[i][j] == ' ')
		cub3d->map.map[i][k] = '2';
	else if (cub3d->map.temp[i][j] == '0')
		cub3d->map.map[i][k] = '0';
	else if (cub3d->map.temp[i][j] == '1')
		cub3d->map.map[i][k] = '1';
	else if (cub3d->map.temp[i][j] == 'N')
		cub3d->map.map[i][k] = 'N';
	else if (cub3d->map.temp[i][j] == 'S')
		cub3d->map.map[i][k] = 'S';
	else if (cub3d->map.temp[i][j] == 'W')
		cub3d->map.map[i][k] = 'W';
	else if (cub3d->map.temp[i][j] == 'E')
		cub3d->map.map[i][k] = 'E';
}

static int	set_line(t_cub3d *cub3d, size_t i)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	cub3d->map.map[i] = ft_calloc(cub3d->map.column + 1, sizeof(char));
	if (!cub3d->map.map[i])
		return (error(strerror(errno)), -1);
	while (cub3d->map.temp[i][j])
	{
		fill_character(cub3d, i, j, k);
		j++;
		k++;
	}
	while (k < cub3d->map.column)
		cub3d->map.map[i][k++] = '2';
	return (0);
}

int	set_map(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	cub3d->map.map = ft_calloc(cub3d->map.row + 1, sizeof(char *));
	if (!cub3d->map.map)
		return (error(strerror(errno)), -1);
	while (i < cub3d->map.row)
	{
		if (set_line(cub3d, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	only_whitespaces(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
