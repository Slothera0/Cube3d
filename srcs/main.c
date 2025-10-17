/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:56 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:24 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int			start_loop(t_cub3d *cub3d);
static int	get_texture_addr(t_img *textures);
static int	init_img(t_cub3d *cub3d);
static void	init_cub3d(t_cub3d *cub3d);
static void	check_extension(char *map);

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	if (argc != 2)
		return (error("Usage: ./cub3d <map.cub>"), 1);
	check_extension(argv[1]);
	cub3d.mlx = mlx_init();
	if (!cub3d.mlx)
		return (error("Couldn't init mlx"), 1);
	init_cub3d(&cub3d);
	if (read_file(&cub3d, argv[1]) == -1)
		return (ft_free(&cub3d), 1);
	get_spawn(&cub3d);
	cub3d.mlx_win = mlx_new_window(cub3d.mlx, WIDTH, HEIGHT, "Francois3d");
	if (!cub3d.mlx_win)
	{
		error("Couldn't create the window");
		ft_free(&cub3d);
		return (1);
	}
	if (init_img(&cub3d) == -1)
		return (1);
	start_loop(&cub3d);
	return (0);
}

static void	check_extension(char *map)
{
	size_t	i;

	i = 0;
	while (map[i + 4])
		i++;
	if (ft_strncmp(&map[i], ".cub", 4))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong file extension", 2);
		exit(EXIT_FAILURE);
	}
}

static void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx_win = NULL;
	cub3d->map.map = NULL;
	cub3d->map.temp = NULL;
	cub3d->map.row = 0;
	cub3d->map.column = 0;
	cub3d->map.start_row = 0;
	cub3d->map.spawns = 0;
	cub3d->img.img = NULL;
	cub3d->textures.textures[0].img = NULL;
	cub3d->textures.textures[1].img = NULL;
	cub3d->textures.textures[2].img = NULL;
	cub3d->textures.textures[3].img = NULL;
	cub3d->textures.ceiling.color = 0;
	cub3d->textures.floor.color = 0;
}

static int	init_img(t_cub3d *cub3d)
{
	cub3d->img.img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->img.img)
	{
		error("Couldn't create img");
		ft_free(cub3d);
		return (-1);
	}
	cub3d->img.img_data = mlx_get_data_addr(cub3d->img.img, &(cub3d->img.bpp),
			&(cub3d->img.size_line), &(cub3d->img.endian));
	if (!cub3d->img.img_data)
	{
		error("Couldn't get img_data");
		ft_free(cub3d);
		return (-1);
	}
	if (get_texture_addr(cub3d->textures.textures) == -1)
	{
		error("Couldn't get img_data");
		ft_free(cub3d);
		return (-1);
	}
	return (0);
}

static int	get_texture_addr(t_img *textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		textures[i].img_data = mlx_get_data_addr(textures[i].img, \
			&(textures[i].bpp), &(textures[i].size_line), \
			&(textures[i].endian));
		if (!textures[i].img_data)
			return (-1);
		i++;
	}
	return (0);
}
