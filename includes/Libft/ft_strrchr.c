/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:44:30 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/10 11:36:49 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	if (s[0] == (char) c)
		ptr = (char *) s;
	while (*s++)
		if (*s == (char) c)
			ptr = (char *) s;
	return (ptr);
}
