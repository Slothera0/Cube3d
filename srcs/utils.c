/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:29:28 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/09/19 22:36:56 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split || !split[0])
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free(t_cub3d *cub3d)
{
	if (cub3d->textures.textures[0].img)
		mlx_destroy_image(cub3d->mlx, cub3d->textures.textures[0].img);
	if (cub3d->textures.textures[1].img)
		mlx_destroy_image(cub3d->mlx, cub3d->textures.textures[1].img);
	if (cub3d->textures.textures[2].img)
		mlx_destroy_image(cub3d->mlx, cub3d->textures.textures[2].img);
	if (cub3d->textures.textures[3].img)
		mlx_destroy_image(cub3d->mlx, cub3d->textures.textures[3].img);
	if (cub3d->map.map)
		free_split(cub3d->map.map);
	if (cub3d->map.temp)
		free_split(cub3d->map.temp);
	if (cub3d->img.img)
		mlx_destroy_image(cub3d->mlx, cub3d->img.img);
	if (cub3d->mlx_win)
		mlx_destroy_window(cub3d->mlx, cub3d->mlx_win);
	if (cub3d->mlx)
	{
		mlx_destroy_display(cub3d->mlx);
		free(cub3d->mlx);
	}
}

size_t	double_ptr_len(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}
