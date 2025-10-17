/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 02:03:56 by arvoyer           #+#    #+#             */
/*   Updated: 2024/09/23 01:32:10 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data_ray	raycasting(t_player player, char **map, double x);
static void	print_line(t_data_ray info, t_textures textures, t_img *img, int x);
void		put_pixel(t_img *img, int x, int y, unsigned int color);

int	print_map(t_cub3d *cub3d)
{
	int			x;
	t_data_ray	info;

	x = 0;
	while (x < WIDTH)
	{
		info = raycasting(cub3d->player, cub3d->map.map, x);
		print_line(info, cub3d->textures, &(cub3d->img), x);
		x++;
	}
	return (0);
}

static void	print_line(t_data_ray info, t_textures t, t_img *img, int x)
{
	double	step;
	double	ratio_p;
	int		img_x;
	int		i;

	i = 0;
	while (i < (-info.wall_height >> 1) + (HEIGHT >> 1))
		put_pixel(img, x, i++, t.floor.color);
	ratio_p = (t.textures[info.side].height / (double)info.wall_height);
	img_x = (int)(info.inter * t.textures[info.side].width);
	if (info.side == EAST || info.side == NORTH)
		img_x = t.textures[info.side].width - img_x - 1;
	step = (i - (HEIGHT >> 1) + (info.wall_height >> 1)) * ratio_p;
	if (step < 0)
		step = 0;
	while (i < (info.wall_height >> 1) + (HEIGHT >> 1) && i < HEIGHT)
	{
		put_pixel(img, x, i, *(unsigned int *)(t.textures[info.side].img_data \
			+ (int)step * t.textures[info.side].size_line + img_x \
			* (t.textures[info.side].bpp >> 3)));
		step += ratio_p;
		i++;
	}
	while (i < HEIGHT)
		put_pixel(img, x, i++, t.ceiling.color);
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*tmp;

	tmp = img->img_data + (y * img->size_line + x * (img->bpp >> 3));
	*(unsigned int *)tmp = color;
}
