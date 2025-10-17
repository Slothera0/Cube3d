/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:07:25 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 14:48:22 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			print_map(t_cub3d *cub3d);
void		rotate(t_cub3d *cub3d);
static void	move_ws(t_cub3d *cub3d);
static void	move_ad(t_cub3d *cub3d);

int	movement_loop(t_cub3d *cub3d)
{
	move_ws(cub3d);
	move_ad(cub3d);
	rotate(cub3d);
	if (cub3d->player.input.w || cub3d->player.input.a
		|| cub3d->player.input.s || cub3d->player.input.d
		|| cub3d->player.input.left || cub3d->player.input.right)
	{
		print_map(cub3d);
		mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, \
			cub3d->img.img, 0, 0);
	}
	return (0);
}

static void	move_ws(t_cub3d *cub3d)
{
	if (cub3d->player.input.w)
	{
		if (cub3d->map.map[(int)(cub3d->player.y + cub3d->player.dir_y
				* MOVE_SPD)][(int)(cub3d->player.x)] == '0')
			cub3d->player.y += cub3d->player.dir_y * MOVE_SPD;
		if (cub3d->map.map[(int)(cub3d->player.y)][(int)(cub3d->player.x
				+ cub3d->player.dir_x * MOVE_SPD)] == '0')
			cub3d->player.x += cub3d->player.dir_x * MOVE_SPD;
	}
	if (cub3d->player.input.s)
	{
		if (cub3d->map.map[(int)(cub3d->player.y - cub3d->player.dir_y
				* MOVE_SPD)][(int)(cub3d->player.x)] == '0')
			cub3d->player.y -= cub3d->player.dir_y * MOVE_SPD;
		if (cub3d->map.map[(int)(cub3d->player.y)][(int)(cub3d->player.x
				- cub3d->player.dir_x * MOVE_SPD)] == '0')
			cub3d->player.x -= cub3d->player.dir_x * MOVE_SPD;
	}
}

static void	move_ad(t_cub3d *cub3d)
{
	if (cub3d->player.input.a)
	{
		if (cub3d->map.map[(int)(cub3d->player.y - cub3d->player.dir_x
				* MOVE_SPD)][(int)(cub3d->player.x)] == '0')
			cub3d->player.y -= cub3d->player.dir_x * MOVE_SPD;
		if (cub3d->map.map[(int)(cub3d->player.y)][(int)(cub3d->player.x
				+ cub3d->player.dir_y * MOVE_SPD)] == '0')
			cub3d->player.x += cub3d->player.dir_y * MOVE_SPD;
	}
	if (cub3d->player.input.d)
	{
		if (cub3d->map.map[(int)(cub3d->player.y + cub3d->player.dir_x
				* MOVE_SPD)][(int)(cub3d->player.x)] == '0')
			cub3d->player.y += cub3d->player.dir_x * MOVE_SPD;
		if (cub3d->map.map[(int)(cub3d->player.y)][(int)(cub3d->player.x
				- cub3d->player.dir_y * MOVE_SPD)] == '0')
			cub3d->player.x -= cub3d->player.dir_y * MOVE_SPD;
	}
}
