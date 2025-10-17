/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:44:26 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 16:29:58 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	get_orientation(t_cub3d *cub3d, char spawn);

int	get_textures(t_cub3d *cub3d, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (error_textures(NULL), -1);
	if (double_ptr_len(split) != 2)
		return (error_textures(split), -1);
	if (ft_strlen(split[0]) > 2)
		return (error_textures(split), -1);
	if (!ft_strncmp(split[0], "NO", 2))
		if (get_north(cub3d, split[1]) == -1)
			return (free_split(split), -1);
	if (!ft_strncmp(split[0], "SO", 2))
		if (get_south(cub3d, split[1]) == -1)
			return (free_split(split), -1);
	if (!ft_strncmp(split[0], "EA", 2))
		if (get_east(cub3d, split[1]) == -1)
			return (free_split(split), -1);
	if (!ft_strncmp(split[0], "WE", 2))
		if (get_west(cub3d, split[1]) == -1)
			return (free_split(split), -1);
	return (free_split(split), 0);
}

int	get_colors(t_cub3d *cub3d, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (error_textures(NULL), -1);
	if (double_ptr_len(split) != 2)
		return (error_textures(split), -1);
	if (ft_strlen(split[0]) > 1)
		return (free_split(split), 0);
	if (!ft_strncmp(split[0], "F", 1))
		if (get_floor_color(cub3d, split[1]) == -1)
			return (free_split(split), -1);
	if (!ft_strncmp(split[0], "C", 1))
		if (get_ceiling_color(cub3d, split[1]) == -1)
			return (free_split(split), -1);
	return (free_split(split), 0);
}

void	get_columns(t_cub3d *cub3d, char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (ft_strlen(line) > cub3d->map.column)
		cub3d->map.column = ft_strlen(line);
}

void	get_spawn(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cub3d->map.row)
	{
		j = 0;
		while (j < cub3d->map.column)
		{
			if (cub3d->map.map[i][j] == 'N' || cub3d->map.map[i][j] == 'S'
				|| cub3d->map.map[i][j] == 'E' || cub3d->map.map[i][j] == 'W')
			{
				cub3d->player.x = j + 0.5;
				cub3d->player.y = i + 0.5;
				get_orientation(cub3d, cub3d->map.map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
	error("There is no spawn");
	ft_free(cub3d);
	exit(EXIT_FAILURE);
}

static void	get_orientation(t_cub3d *cub3d, char spawn)
{
	cub3d->player.dir_x = 0;
	cub3d->player.dir_y = 0;
	cub3d->player.plane_x = 0;
	cub3d->player.plane_y = 0;
	if (spawn == 'N')
	{
		cub3d->player.dir_y = -1;
		cub3d->player.plane_x = 0.66;
	}
	else if (spawn == 'S')
	{
		cub3d->player.dir_y = 1;
		cub3d->player.plane_x = -0.66;
	}
	else if (spawn == 'E')
	{
		cub3d->player.dir_x = 1;
		cub3d->player.plane_y = 0.66;
	}
	else if (spawn == 'W')
	{
		cub3d->player.dir_x = -1;
		cub3d->player.plane_y = -0.66;
	}
}
