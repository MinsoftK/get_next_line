/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:10:08 by minsungk          #+#    #+#             */
/*   Updated: 2021/01/12 22:10:09 by minsungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define READ 1
# define EOF 0
# define ERROR -1

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef	OPEN_MAX
# define OPEN_MAX 256
#endif

int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
