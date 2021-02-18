/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@stduent.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:18 by minsungk          #+#    #+#             */
/*   Updated: 2021/02/18 21:33:57 by minsungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		have_newline(const char *backupfd)
{
	size_t idx;

	idx = 0;
	while (backupfd[idx])
	{
		if (backupfd[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		split_newline(char **backup, char **line, size_t new_idx)
{
	size_t	len;
	char	*temp;

	(*backup)[new_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + new_idx + 1);
	if (len == 0)
	{
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + new_idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char 			buff[BUFFER_SIZE];
	static char		*backup[OPEN_MAX];
	size_t			rd_size;
	size_t			new_idx;

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (ERROR);
	while (0 < (rd_size = read(fd, (char *)buff, BUFFER_SIZE - 1)))
	{
		// buff[rd_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((new_idx = have_newline(backup[fd])) >= 0)
			return (split_newline(&backup[fd], line, new_idx));
	}
	return ();
}
