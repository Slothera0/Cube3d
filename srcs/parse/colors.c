/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:03:27 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 16:28:25 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <errno.h>
#include <string.h>

static int	is_rgb_color(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str) > 3)
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (ft_atoi(str) > 255)
		return (-1);
	return (ft_atoi(str));
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_floor_color(t_cub3d *cub3d, char *texture)
{
	char	**split;

	split = ft_split(texture, ',');
	if (!split)
		return (error(strerror(errno)), -1);
	if (double_ptr_len(split) != 3)
	{
		error("Invalid floor (F) color");
		return (free_split(split), -1);
	}
	split[2][ft_strlen(split[2]) - 1] = '\0';
	cub3d->textures.floor.r = is_rgb_color(split[0]);
	cub3d->textures.floor.g = is_rgb_color(split[1]);
	cub3d->textures.floor.b = is_rgb_color(split[2]);
	if (cub3d->textures.floor.r == -1 || cub3d->textures.floor.g == -1
		|| cub3d->textures.floor.b == -1)
	{
		error("Invalid floor (F) color");
		return (free_split(split), -1);
	}
	cub3d->textures.floor.color = create_rgb(cub3d->textures.floor.r,
			cub3d->textures.floor.g, cub3d->textures.floor.b);
	free_split(split);
	return (0);
}

int	get_ceiling_color(t_cub3d *cub3d, char *texture)
{
	char	**split;

	split = ft_split(texture, ',');
	if (!split)
		return (error(strerror(errno)), -1);
	if (double_ptr_len(split) != 3)
	{
		error("Invalid ceiling (C) color");
		return (free_split(split), -1);
	}
	split[2][ft_strlen(split[2]) - 1] = '\0';
	cub3d->textures.ceiling.r = is_rgb_color(split[0]);
	cub3d->textures.ceiling.g = is_rgb_color(split[1]);
	cub3d->textures.ceiling.b = is_rgb_color(split[2]);
	if (cub3d->textures.ceiling.r == -1 || cub3d->textures.ceiling.g == -1
		|| cub3d->textures.ceiling.b == -1)
	{
		error("Invalid ceiling (C) color");
		return (free_split(split), -1);
	}
	cub3d->textures.ceiling.color = create_rgb(cub3d->textures.ceiling.r,
			cub3d->textures.ceiling.g, cub3d->textures.ceiling.b);
	free_split(split);
	return (0);
}
