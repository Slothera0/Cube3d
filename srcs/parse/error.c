/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:32:59 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/08/21 23:37:00 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_textures(char **to_free)
{
	if (to_free)
		free_split(to_free);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("An error occurred while getting textures", 2);
}

void	error(char *err)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err, 2);
}
