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

# define READ 1
# define EOF 0
# define ERROR -1

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

int		get_next_line(int fd, char **line);



#endif
