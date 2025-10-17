/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:59:05 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/09/19 23:03:16 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	rotate_left(t_cub3d *cub3d);
static void	rotate_right(t_cub3d *cub3d);

void	rotate(t_cub3d *cub3d)
{
	if (cub3d->player.input.left)
		rotate_left(cub3d);
	if (cub3d->player.input.right)
		rotate_right(cub3d);
}

static void	rotate_left(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player.dir_x;
	cub3d->player.dir_x = cub3d->player.dir_x * cos(-R_SPD)
		- cub3d->player.dir_y * sin(-R_SPD);
	cub3d->player.dir_y = old_dir_x * sin(-R_SPD)
		+ cub3d->player.dir_y * cos(-R_SPD);
	old_plane_x = cub3d->player.plane_x;
	cub3d->player.plane_x = cub3d->player.plane_x * cos(-R_SPD)
		- cub3d->player.plane_y * sin(-R_SPD);
	cub3d->player.plane_y = old_plane_x * sin(-R_SPD)
		+ cub3d->player.plane_y * cos(-R_SPD);
}

static void	rotate_right(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player.dir_x;
	cub3d->player.dir_x = cub3d->player.dir_x * cos(R_SPD)
		- cub3d->player.dir_y * sin(R_SPD);
	cub3d->player.dir_y = old_dir_x * sin(R_SPD)
		+ cub3d->player.dir_y * cos(R_SPD);
	old_plane_x = cub3d->player.plane_x;
	cub3d->player.plane_x = cub3d->player.plane_x * cos(R_SPD)
		- cub3d->player.plane_y * sin(R_SPD);
	cub3d->player.plane_y = old_plane_x * sin(R_SPD)
		+ cub3d->player.plane_y * cos(R_SPD);
}
