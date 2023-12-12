/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:03:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/12 06:04:59 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*result;
	size_t	index;
	size_t	len;

	index = 0;
	len = 0;
	if (!s1)
		len = (ft_strlen(s2) + 1);
	else
		len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = (char *)malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	len = 0;
	while (s1[index] != '\0')
	{
		result[index] = s1[index];
		index++;
	}
	while (s2[len] != '\0')
		result[index++] = s2[len++];
	result[index] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	find;
	int				i;

	find = (unsigned char)c;
	str = (char *)s;
	i = 0;
	if (find == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (str[i])
	{
		if (find == str[i])
			return (&str[i]);
		i++;
	}
	return (NULL);
}

