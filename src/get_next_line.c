/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/08 23:11:54 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
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
		return ((char *)s2);
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

char	*get_chars(int fd)
{
	char *line;
	char *temp;
	ssize_t nbytes = 1;

	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	temp[0] = '\0';
	line = ft_strjoin("", "");
	while (nbytes > 0)
	{
		if (ft_strchr(temp, '\n'))
			break;
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes < 1)
			break;
		line = ft_strjoin(line, temp);
	}
	

	return(line);
} 

char	*get_leftover(char *get_read)
{
	char	*found;
	char	*copy;
	char	*leftover;
	int		leftover_size;	
	int 	i;	
	
	i = 0;
	leftover_size = 0;
	found = ft_strchr(get_read, '\n');
	found++;
	copy = found;
	while (*found)
	{
		found++;
		leftover_size++;
	}
	leftover = malloc(leftover_size * sizeof(char));
	while (i < leftover_size)
	{
		leftover[i] = *copy;
		i++;
		copy++;
	}
	leftover[leftover_size] = '\0';
	return (leftover);
}


char	*get_line_trim(char *get_read)
{
	char	*trimmed_read;
	int		i;	

	i = 0;
	while (get_read[i] != '\n')
		i++;
	trimmed_read = malloc(i + 1 * sizeof(char));
	i = 0;
	while (get_read[i] != '\n')
	{
		trimmed_read[i] = get_read[i];
		i++;
	}
	trimmed_read[i] = '\n';
	i++;
	trimmed_read[i] = '\0';
	
	free(get_read);
	return (trimmed_read);
}


char	*get_next_line(int fd)
{
	
	char *get_read;
	char *line;
	char *output;
	static char *leftover;

	get_read = get_chars(fd);
	line = ft_strjoin(leftover, get_read);
	leftover = get_leftover(get_read);
	output = get_line_trim(line);

//	free(leftover);

//	printf("\nget_read          : '%s'",get_read);
//	printf("\nget_read_trim     : '%s'",trimmed_read);
//	printf("\nline              : '%s'",line);
//	printf("\nleftover          : '%s'",leftover);

	return (output);
}
