/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@stduent.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:18 by minsungk          #+#    #+#             */
/*   Updated: 2021/03/02 19:10:34 by minsungk         ###   ########.fr       */
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

int		set_newline(char **backup, char **line)
{
	int		newline_idx;
	int		result;
	char	*temp;

	newline_idx = have_newline(*backup);
	(*backup)[newline_idx] = '\0';
	*line = ft_strdup(*backup);
	result = (((*line)[newline_idx] == '\0') ? READ : EndLine);
	temp = ft_strdup(*backup + newline_idx + 1);
	if (*backup && result == EndLine)
		free (*backup);
	*backup = temp;
	return (result);
}

int		error(char **backup)
{
	if (*backup)
		free (*backup);
	*backup = NULL;
	return (ERROR);
}

int		final_reset(char **backup, char **line)
{
	*line = ft_strnul();
	if (*backup)
		free (*backup);
	*backup = NULL;
	return (EndLine);
}

int		get_next_line(int fd, char **line)
{
	char 			buff[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];
	long long		len;
	char			*tmp_str;

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	while (!(ft_strchr(backup[fd], '\n')) && \
	0 < (len = read(fd, (char *)buff, BUFFER_SIZE)))
	{
		buff[len] = '\0';
		tmp_str = ft_strjoin(backup[fd], buff);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp_str;
	}
	if (len < 0)
		return (error(&(backup[fd])));
	if (len == 0 && backup[fd][0] == '\0')
		return (final_reset(&(backup[fd]), line));
	return (set_newline(&(backup[fd]), line));
}
