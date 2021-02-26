/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@stduent.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:18 by minsungk          #+#    #+#             */
/*   Updated: 2021/02/23 17:13:13 by minsungk         ###   ########.fr       */
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
	return (ERROR);
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
		free(*backup);
	*backup = NULL;
	return (ERROR);
}

int		final_reset(char **backup, char **line)
{
	char *temp;

	temp = (char *)malloc(1);
	*temp = '\0';
	*line = temp;
	if (*backup)
		free(*backup);
	*backup = NULL;
	return ();
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];
	long long		len;
	char			*tmp_str;

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
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
