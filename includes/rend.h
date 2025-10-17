/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 06:46:36 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/15 14:30:21 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REND_H
# define REND_H

# include <stdbool.h>
# include "cub3d.h"

# define MOVE_SPD 0.013
# define R_SPD 0.008
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_input
{
	bool	w;
	bool	d;
	bool	a;
	bool	s;
	bool	left;
	bool	right;
}	t_input;

typedef struct s_player
{
	t_input	input;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	int		pos;
	int		step;
	double	dir;
	double	delta_dist;
	double	side_dist;
}	t_ray;

typedef struct s_data_ray
{
	int		wall_height;
	int		side;
	double	inter;
}	t_data_ray;

#endif