/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:34:21 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/06/15 17:16:15 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add(char *big, char stash[BUFFER_SIZE + 1])
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*new;

	size = ft_strlen(stash) + ft_strlen(big);
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (free(big), NULL);
	i = 0;
	j = 0;
	while (big[i])
	{
		new[i] = big[i];
		i++;
	}
	while (stash[j])
	{
		new[i + j] = stash[j];
		j++;
	}
	free(big);
	return (new);
}
