/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:46:29 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 16:33:43 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	around(t_cub3d *cub3d, size_t row, size_t col)
{
	if (cub3d->map.map[row - 1][col] == '2'
		|| cub3d->map.map[row + 1][col] == '2'
		|| cub3d->map.map[row][col - 1] == '2'
		|| cub3d->map.map[row][col + 1] == '2')
	{
		return (0);
	}
	if (cub3d->map.map[row - 1][col] == '\0'
		|| cub3d->map.map[row + 1][col] == '\0'
		|| cub3d->map.map[row][col - 1] == '\0'
		|| cub3d->map.map[row][col + 1] == '\0')
	{
		return (0);
	}
	return (1);
}

int	map_validity_checker(t_cub3d *cub3d, const char *row)
{
	size_t	i;

	i = 0;
	while (row[i])
	{
		if (row[i] == 'N' || row[i] == 'S' || row[i] == 'E' || row[i] == 'W')
			cub3d->map.spawns++;
		else if (row[i] != '0' && row[i] != '1'
			&& row[i] != ' ' && row[i] != '\n')
			return (error("Invalid character in the map"), -1);
		if (cub3d->map.spawns > 1)
			return (error("Too many spawns"), -1);
		i++;
	}
	return (0);
}

int	check_empty(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub3d->map.map[i])
	{
		j = 0;
		while (cub3d->map.map[i][j])
		{
			if (cub3d->map.map[i][j] == '0' || cub3d->map.map[i][j] == 'N'
				|| cub3d->map.map[i][j] == 'S'
				|| cub3d->map.map[i][j] == 'E'
				|| cub3d->map.map[i][j] == 'W')
			{
				if (i == 0 || j == 0 || j == cub3d->map.column - 1
					|| i == cub3d->map.row - 1)
					return (error("Map not closed"), -1);
				if (!around(cub3d, i, j))
					return (error("Map not closed"), -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_init(t_cub3d *cub3d)
{
	if (!cub3d->textures.textures[0].img)
		return (0);
	if (!cub3d->textures.textures[1].img)
		return (0);
	if (!cub3d->textures.textures[2].img)
		return (0);
	if (!cub3d->textures.textures[3].img)
		return (0);
	if (!cub3d->textures.floor.color)
		return (0);
	if (!cub3d->textures.ceiling.color)
		return (0);
	return (1);
}

int	valid_texture_name(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (error_textures(NULL), -1);
	if (!ft_strncmp(split[0], "NO", ft_strlen(split[0]))
		|| !ft_strncmp(split[0], "SO", ft_strlen(split[0]))
		|| !ft_strncmp(split[0], "EA", ft_strlen(split[0]))
		|| !ft_strncmp(split[0], "WE", ft_strlen(split[0]))
		|| !ft_strncmp(split[0], "C", ft_strlen(split[0]))
		|| !ft_strncmp(split[0], "F", ft_strlen(split[0])))
		return (free_split(split), 0);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(split[0], 2);
	ft_putendl_fd(" is not a correct texture name", 2);
	free_split(split);
	return (-1);
}
