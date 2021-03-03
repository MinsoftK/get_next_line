/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@stduent.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:46 by minsungk          #+#    #+#             */
/*   Updated: 2021/03/02 18:17:53 by minsungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnul(void)
{
	char *result;

	result = (char *)malloc(1);
	*result = '\0';
	return (result);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (temp)
	{
		i = 0;
		while (*s1)
		{
			temp[i++] = *s1;
		}
		while (*s2)
		{
			temp[i++] = *s2;
			s2++;
		}
		temp[i] = '\0';
	}
	return (temp);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	temp;
	char	*stemp;

	i = 0;
	temp = (char)ch;
	stemp = (char *)str;
	if (!str)
		return (NULL);
	while (stemp[i] != temp)
	{
		if (stemp[i] == '\0')
			return (NULL);
		i++;
	}
	return (&stemp[i]);
}

char	*ft_sizepush(char *backup, int size)
{
	int i;

	i = 0;
	while (backup[i + size])
	{
		backup[i] = backup[i + size];
		i++;
	}
	while (backup[i])
		backup[i++] = '\0';
	return (backup);
}
