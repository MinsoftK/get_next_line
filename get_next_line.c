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

void	ft_str(const char *s1)
{
	while (*s1)
	{
		write(1, &s1, 1);
		s1++;
	}
}

int		is_newline(const char *buff)
{
	size_t idx;

	idx = 0;
	while (buff[idx])
	{
		if (buff[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		print_gnl(char **backup, char **line, size_t new_idx)
{
	
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
		//rd_size 만큼의 동적할당 후, 출력 그리고 그 다음의 포인터 주소도 가지고 있어야 한다.
		buff[rd_size] = '\0';
	
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((new_idx = is_newline(buff[fd])) > 0)
		{
			//출력하는 부분
			print_gnl(&backup[fd], line, new_idx);
		}
		//idx 의 인덱스 출력 test


	}
	//1234\n5678\n
}
