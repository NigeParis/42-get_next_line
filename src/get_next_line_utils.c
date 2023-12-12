/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:03:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/12 16:53:12 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	index;
	size_t	len;
	int 	flag;

	index = 0;
	len = 0;
	flag = 0;
	if (!s1)
	{
		flag = 1;
		s1 = malloc(1 * sizeof(char *));
		s1[0] = '\0';
	}
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = (char *)malloc(len * sizeof(char *));
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
	if (flag)
		free(s1);
	return (result);
}
/*
char	*ft_strjoin(char *s1, char *s2)
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
}*/





char	*ft_strchr(char *s, int c)
{
	char			*str;
	unsigned char	find;
	int				i;

	find = c;
	str = s;
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

