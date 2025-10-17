/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:03:22 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/10/16 15:51:24 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	init_textures(t_cub3d *cub3d, char **line, int fd)
{
	cub3d->map.start_row++;
	if (only_whitespaces(*line))
		return (0);
	if (valid_texture_name((*line)))
		return (-1);
	if (get_textures(cub3d, (*line)) == -1)
		return (-1);
	if (get_colors(cub3d, (*line)) == -1)
		return (-1);
	if (check_init(cub3d))
	{
		free((*line));
		(*line) = get_next_line(fd);
		while ((*line) && ft_strlen((*line)) == 1 && (*line)[0])
		{
			free((*line));
			(*line) = get_next_line(fd);
			cub3d->map.start_row++;
		}
		if (!(*line) || parse_line(*line))
			return (error("Invalid map"), -1);
	}
	return (0);
}

int	init_map(t_cub3d *cub3d, char *line)
{
	if (ft_strlen(line) == 1 && line[0] == '\n')
		return (error("Invalid map (\\n misplaced"
				", becareful if you placed \\n below the map)"), -1);
	get_columns(cub3d, line);
	cub3d->map.row++;
	return (0);
}
