/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:05:42 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/15 15:45:02 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

void		error(char *err);

int			read_file(t_cub3d *cub3d, char *map);

int			get_colors(t_cub3d *cub3d, char *line);
int			get_textures(t_cub3d *cub3d, char *line);
void		get_columns(t_cub3d *cub3d, char *line);
void		get_spawn(t_cub3d *cub3d);

int			get_north(t_cub3d *cub3D, char *texture);
int			get_south(t_cub3d *cub3D, char *texture);
int			get_east(t_cub3d *cub3D, char *texture);
int			get_west(t_cub3d *cub3D, char *texture);
int			get_floor_color(t_cub3d *cub3D, char *texture);
int			get_ceiling_color(t_cub3d *cub3D, char *texture);

int			init_textures(t_cub3d *cub3d, char **line, int fd);
int			init_map(t_cub3d *cub3d, char *line);

int			set_map(t_cub3d *cub3d);
int			map_validity_checker(t_cub3d *cub3d, const char *row);
int			check_empty(t_cub3d *cub3d);
void		error_textures(char **to_free);
int			only_whitespaces(char *line);
int			is_whitespace(char c);
int			check_init(t_cub3d *cub3d);
int			valid_texture_name(char *line);

#endif
