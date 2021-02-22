/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:18 by minsungk          #+#    #+#             */
/*   Updated: 2021/01/12 22:09:19 by minsungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_newline(const char *backup)
{
	size_t idx;

	idx = 0;
	while (backup[idx])
	{
		if (backup[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		set_newline(char **backup, char **line)
{
	char	*temp;
	int 	len;

	*backup[len] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + len + 1)
	
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char 			buff[BUFFER_SIZE];
	static char		*backup[OPEN_MAX];
	long long		len;
	char			*tmp_str;

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, buff, 0))
		return (-1);
	while (!(ft_strchr(buff[fd], '\n')) && \
	0 < (len = read(fd, (char *)buff, BUFFER_SIZE - 1)))
	{
		buff[len] = '\0';
		tmp_str = ft_strjoin(backup[fd], buff);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp_str;
	}
	return (return_all());
}

