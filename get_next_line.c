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

int		set_newline(char **backup, char **line)
{
	int		result;
	int		size;
	int		i;
	char	*temp;

	size = 0;
	while ((*backup)[size] && (*backup)[size] != '\n')
		size++;
	*line = (char *)malloc(size + 1);
	i = 0;
	while (i < size)
	{
		(*line)[i] = (*backup)[i];
		i++;
	}
	(*line)[i] = '\0';
	result = (((*backup)[size] == '\n') ? READ : EOFLINE);
	temp = (result ? ft_sizepush(*backup, size + 1) : NULL);
	if (result == EOFLINE && *backup)
		free(*backup);
	*backup = temp;
	return (result);
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
	*line = ft_strnul();
	if (*backup)
		free(*backup);
	*backup = NULL;
	return (EOFLINE);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];
	long long		len;
	char			*tmp_str;

	if (fd < 0 || !line || fd >= OPEN_MAX || BUFFER_SIZE <= 0 \
	|| read(fd, buff, 0) == -1)
		return (ERROR);
	if (!backup[fd])
		backup[fd] = ft_strnul();
	while (!(ft_strchr(backup[fd], '\n')) && \
	0 < (len = read(fd, (char *)buff, BUFFER_SIZE)))
	{
		buff[len] = '\0';
		if ((tmp_str = ft_strjoin(backup[fd], buff)) == NULL)
			return (ERROR);
		if (backup[fd])			//check 해볼 부분 : tmp_str에서 동적할당을 실패했을 경우 backup의 free가 동시에 돼야 한다. 점수와는 연관이 없다.
			free(backup[fd]);
		backup[fd] = tmp_str;
	}
	if (len < 0)
		return (error(&(backup[fd])));
	if (len == 0 && backup[fd][0] == '\0')
		return (final_reset(&(backup[fd]), line));
	return (set_newline(&(backup[fd]), line));
}
