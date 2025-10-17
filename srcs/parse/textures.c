/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:02:57 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 16:43:16 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_north(t_cub3d *cub3d, char *texture)
{
	t_img	*img;

	img = &cub3d->textures.textures[0];
	texture[ft_strlen(texture) - 1] = '\0';
	if (img->img)
	{
		error("Multiple definition of the north (NO) texture");
		return (-1);
	}
	img->img = mlx_xpm_file_to_image(cub3d->mlx,
			texture, &(img->width), &(img->height));
	if (!img->img)
	{
		error("Incorrect north (NO) texture");
		return (-1);
	}
	return (0);
}

int	get_south(t_cub3d *cub3d, char *texture)
{
	t_img	*img;

	img = &cub3d->textures.textures[1];
	texture[ft_strlen(texture) - 1] = '\0';
	if (img->img)
	{
		error("Multiple definition of the south (SO) texture");
		return (-1);
	}
	img->img = mlx_xpm_file_to_image(cub3d->mlx,
			texture, &(img->width), &(img->height));
	if (!img->img)
	{
		error("Incorrect south (SO) texture");
		return (-1);
	}
	return (0);
}

int	get_east(t_cub3d *cub3d, char *texture)
{
	t_img	*img;

	img = &cub3d->textures.textures[2];
	texture[ft_strlen(texture) - 1] = '\0';
	if (img->img)
	{
		error("Multiple definition of the east (EA) texture");
		return (-1);
	}
	img->img = mlx_xpm_file_to_image(cub3d->mlx,
			texture, &(img->width), &(img->height));
	if (!img->img)
	{
		error("Incorrect east (EA) texture");
		return (-1);
	}
	return (0);
}

int	get_west(t_cub3d *cub3d, char *texture)
{
	t_img	*img;

	img = &cub3d->textures.textures[3];
	texture[ft_strlen(texture) - 1] = '\0';
	if (img->img)
	{
		error("Multiple definition of the west (WE) texture");
		return (-1);
	}
	img->img = mlx_xpm_file_to_image(cub3d->mlx,
			texture, &(img->width), &(img->height));
	if (!img->img)
	{
		error("Incorrect west (WE) texture");
		return (-1);
	}
	return (0);
}
