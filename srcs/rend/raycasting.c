/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:33:40 by arvoyer           #+#    #+#             */
/*   Updated: 2024/09/23 02:10:34 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static t_ray	init_ray(double dir, double pos);
static int		dda(t_ray *ray, char **map);
static int		set_side(int side, t_player player, double camera);

t_data_ray	raycasting(t_player player, char **map, double x)
{
	t_ray		ray[2];
	t_data_ray	info;
	double		camera;
	int			side;
	double		wall_d;

	camera = 2 * x / WIDTH - 1;
	ray[0] = init_ray(player.dir_x + player.plane_x * camera, player.x);
	ray[1] = init_ray(player.dir_y + player.plane_y * camera, player.y);
	side = dda(ray, map);
	if (side == 0)
	{
		wall_d = (ray[0].pos - player.x + (1 - ray[0].step) / 2) / ray[0].dir;
		info.inter = player.y + wall_d * ray[1].dir;
	}
	else
	{
		wall_d = (ray[1].pos - player.y + (1 - ray[1].step) / 2) / ray[1].dir;
		info.inter = player.x + wall_d * ray[0].dir;
	}
	info.side = set_side(side, player, camera);
	info.inter -= (int)info.inter;
	info.wall_height = (int)(HEIGHT / wall_d);
	return (info);
}

static t_ray	init_ray(double dir, double pos)
{
	t_ray	ray;

	ray.delta_dist = fabs(1 / dir);
	ray.pos = pos;
	ray.dir = dir;
	if (dir < 0)
	{
		ray.step = -1;
		ray.side_dist = (pos - ray.pos) * ray.delta_dist;
	}
	else
	{
		ray.step = 1;
		ray.side_dist = (ray.pos + 1 - pos) * ray.delta_dist;
	}
	return (ray);
}

static int	dda(t_ray *ray, char **map)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (ray[0].side_dist < ray[1].side_dist)
		{
			ray[0].side_dist += ray[0].delta_dist;
			ray[0].pos += ray[0].step;
			side = 0;
		}
		else
		{
			ray[1].side_dist += ray[1].delta_dist;
			ray[1].pos += ray[1].step;
			side = 1;
		}
		if (map[ray[1].pos][ray[0].pos] == '1')
			hit = 1;
	}
	return (side);
}

static int	set_side(int side, t_player player, double camera)
{
	if (player.dir_x + player.plane_x * camera > 0 && side == 0)
		return (WEST);
	else if (side == 0)
		return (EAST);
	else if (player.dir_y + player.plane_y * camera > 0)
		return (NORTH);
	return (SOUTH);
}
