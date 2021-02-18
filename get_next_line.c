/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@stduent.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:18 by minsungk          #+#    #+#             */
/*   Updated: 2021/02/18 17:16:40 by minsungk         ###   ########.fr       */
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
	size_t temp;
	char *temp1;
	temp = ft_strlen(*backup);
	(*backup)[new_idx] = '\0';
	free(*backup);
	*backup = *backup + new_idx;
	
	*line = ft_strdup(*backup);

	*backup = *backup
}

int		get_next_line(int fd, char **line)
{
	char 			buff[BUFFER_SIZE];
	static char		*backup[OPEN_MAX];
	size_t			rd_size;
	size_t			new_idx;

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	while (0 < (rd_size = read(fd, (char *)buff, BUFFER_SIZE - 1)))
	{
		buff[rd_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((new_idx = have_newline(backup[fd])) >= 0)
			return (split_newline(&backup[fd], line, new_idx));
	}
	return ()
}

