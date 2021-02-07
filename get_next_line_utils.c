/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsungk <minsungk@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:09:46 by minsungk          #+#    #+#             */
/*   Updated: 2021/01/12 22:09:48 by minsungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t temp;

	i = 0;
	temp = ft_strlen(src);
	if (!dest || !src)
		return (0);
	while (i < temp && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (temp);
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
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (*s1 == 0 && *s2 == 0)
		return (ft_strdup(""));
	if (!(temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (++i < len1)
		temp[i] = s1[i];
	while (++j < len2)
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	return (temp);
}

void	*ft_strdup(const char *s)
{
	int		len;
	char	*temp;
	int		i;

	i = 0;
	len = ft_strlen(s);
	if (!((temp = (char *)malloc(sizeof(char) * (len + 1)))))
	return (NULL);
	while (i < len)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
