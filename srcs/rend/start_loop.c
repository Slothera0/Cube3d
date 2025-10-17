/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:44:00 by arvoyer           #+#    #+#             */
/*   Updated: 2024/09/23 01:29:42 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			movement_loop(t_cub3d *cub3d);
int			print_map(t_cub3d *cub3d);
static int	close_window(t_cub3d *cub3d);
static void	init_player_info(t_player *player);
static int	press_input(int keysym, t_cub3d *cub3d);
static int	release_input(int keysym, t_cub3d *cub3d);

int	start_loop(t_cub3d *cub3d)
{
	cub3d->map.map[(int)cub3d->player.y][(int)cub3d->player.x] = '0';
	init_player_info(&(cub3d->player));
	print_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, cub3d->img.img, 0, 0);
	mlx_hook(cub3d->mlx_win, 2, (1L << 0), &press_input, cub3d);
	mlx_hook(cub3d->mlx_win, 3, (1L << 1), &release_input, cub3d);
	mlx_hook(cub3d->mlx_win, 17, (1L << 0), &close_window, cub3d);
	mlx_loop_hook(cub3d->mlx, &movement_loop, cub3d);
	mlx_loop(cub3d->mlx);
	close_window(cub3d);
	return (0);
}

static void	init_player_info(t_player *player)
{
	player->input.w = false;
	player->input.a = false;
	player->input.s = false;
	player->input.d = false;
	player->input.left = false;
	player->input.right = false;
}

static int	press_input(int keysym, t_cub3d *cub3d)
{
	if (keysym == XK_Escape)
		close_window(cub3d);
	if (keysym == XK_w)
		cub3d->player.input.w = true;
	else if (keysym == XK_s)
		cub3d->player.input.s = true;
	else if (keysym == XK_d)
		cub3d->player.input.d = true;
	else if (keysym == XK_a)
		cub3d->player.input.a = true;
	else if (keysym == XK_Left)
		cub3d->player.input.left = true;
	else if (keysym == XK_Right)
		cub3d->player.input.right = true;
	return (0);
}

static int	release_input(int keysym, t_cub3d *cub3d)
{
	if (keysym == XK_w)
		cub3d->player.input.w = false;
	else if (keysym == XK_s)
		cub3d->player.input.s = false;
	else if (keysym == XK_d)
		cub3d->player.input.d = false;
	else if (keysym == XK_a)
		cub3d->player.input.a = false;
	else if (keysym == XK_Left)
		cub3d->player.input.left = false;
	else if (keysym == XK_Right)
		cub3d->player.input.right = false;
	return (0);
}

static int	close_window(t_cub3d *cub3d)
{
	mlx_loop_end(cub3d->mlx);
	ft_free(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}
