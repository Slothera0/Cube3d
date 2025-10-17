/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:34:41 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 14:16:04 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "mlx.h"
# include "rend.h"

# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>

# define WIDTH 640
# define HEIGHT 480

typedef struct s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	void	*img;
	char	*img_data;
}	t_img;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	unsigned int	color;
}	t_color;

typedef struct s_textures
{
	t_img	textures[4];
	t_color	ceiling;
	t_color	floor;
}	t_textures;

typedef struct s_map
{
	char	**map;
	char	**temp;
	size_t	row;
	size_t	column;
	size_t	start_row;
	size_t	spawns;
}	t_map;

typedef struct s_cub3d
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_textures	textures;
	t_player	player;
	t_img		img;
}	t_cub3d;

void	ft_free(t_cub3d *cub3D);
void	free_split(char **split);
size_t	double_ptr_len(char **ptr);

#endif
