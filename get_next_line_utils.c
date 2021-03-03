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

char 	*ft_strnul(void)
{
	char *result;
	
	result = (char *)malloc(1);
	*result = '\0';
	return (result);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*temp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	if (!(temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (++i < len1)
		temp[i] = s1[i];
	while (++j < len2)
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
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

int		ft_sizepush(char *backup, int size)
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
