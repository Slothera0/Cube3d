/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:53:31 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/06/19 13:52:35 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *big)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!big[i])
		return (free(big), NULL);
	while (big[i] && big[i] != '\n')
		i++;
	if (big[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(big), NULL);
	i = 0;
	while (big[i] && big[i] != '\n')
	{
		line[i] = big[i];
		i++;
	}
	if (big[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_next(char *stash, char *big)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		if (big)
			free(big);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		stash[j++] = stash[i++];
	stash[j] = '\0';
	return (free(big), stash);
}

static void	ft_stash_clear(char stash[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
		stash[i++] = 0;
}

static char	*read_file(int fd, char stash[BUFFER_SIZE + 1])
{
	ssize_t	bytes;
	char	*big;

	big = ft_calloc(1, 1);
	if (!big)
		return (NULL);
	bytes = 1;
	if (stash[0])
	{
		big = ft_add(big, stash);
		if (!big)
			return (NULL);
	}
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes == -1)
			return (free(big), ft_stash_clear(stash), NULL);
		stash[bytes] = 0;
		big = ft_add(big, stash);
		if (!big)
			return (NULL);
	}
	return (big);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*big;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) == -1)
	{
		if (stash[0])
			ft_stash_clear(stash);
		return (NULL);
	}
	big = read_file(fd, stash);
	if (!big)
		return (NULL);
	line = ft_get_line(big);
	if (!line)
		return (NULL);
	ft_next(stash, big);
	return (line);
}
