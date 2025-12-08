/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/20 17:19:58 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_get_line(char **buffer);
void	create_list(char **buffer, size_t fd);

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(char *s, size_t c);
char	*gnl_strjoin(char **buffer, char *list);
size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize);

#endif
