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

int		set_newline(char **backup, char **line, size_t new_idx)
{
	char	*temp;
	int 	len;
	
	*backup[new_idx] = '\0';
	temp = ft_strdup()
	return (0);
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
		if ((new_idx = is_newline(backup[fd])) >= 0)
			return (set_newline(&backup[fd], line, new_idx));
	}
	return (return_all())
}

