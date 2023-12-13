/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:03:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/13 19:18:29 by nrobinso         ###   ########.fr       */
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

	if (s1[0] == '\0')
		len = (ft_strlen(s2) + 1);
	else
		len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = malloc(len * sizeof(char));
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


char	*ft_joinchars(char *s1, char *s2)
{
	char	*result;
	size_t	index;
	size_t	len;
	int 	flag;

	index = 0;
	len = 0;
	flag = 0;

	if (s1[0] == '\0')
		len = (ft_strlen(s2) + 2);
	else
		len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = malloc(len * sizeof(char));
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


char	*ft_strdup(char *s1)
{
	char	*str;
	char	*to_copy;
	size_t	size;

	to_copy = (char *)s1;
	size = ft_strlen(s1);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, to_copy, size + 1);
	return (str);
}


size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int	len;
	char	*dest;
	char	*tocopy;
	size_t	i;

	len = 0;
	tocopy = NULL;
	len = ft_strlen(src);
	dest = dst;
	tocopy = (char *)src;
	i = 0;
	if (len == 0 && dstsize == 0)
		return (len);
	if (len == 0)
		*dest = '\0';
	if (dstsize < 1 || len < 2)
		return (len);
	while (i < dstsize - 1 && tocopy[i] != '\0')
	{
		dest[i] = tocopy[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
