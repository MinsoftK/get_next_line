/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@stduent.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:18 by minsungk          #+#    #+#             */
/*   Updated: 2021/03/02 18:18:31 by minsungk         ###   ########.fr       */
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

int		split_newline(char **backup, char **line)
{
	size_t	newline_idx;
	size_t	len;
	char	*temp;

	newline_idx = have_newline(*backup);
	*line = ft_substr(*backup, 0, newline_idx);
	len = ft_strlen(*backup);
	if (len == 0)
	{
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + newline_idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
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
	return (split_newline(&(backup[fd]), line));
}
