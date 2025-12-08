/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:39:42 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/20 17:19:32 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, size_t c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char **buffer, char *list)
{
	size_t	i;
	size_t	j;
	char	*news;

	i = -1;
	j = -1;
	if (!*buffer)
	{
		*buffer = malloc(1);
		(*buffer)[0] = 0;
	}
	news = malloc(gnl_strlen(list) + gnl_strlen(*buffer) + 1);
	if (news == NULL)
		return (NULL);
	while ((*buffer)[++i])
		news[i] = (*buffer)[i];
	while (list[++j])
		news[i + j] = list[j];
	news[i + j] = 0;
	free(*buffer);
	*buffer = news;
	return (*buffer);
}

size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (gnl_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (gnl_strlen(src));
}
