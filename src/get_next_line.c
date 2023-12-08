/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/08 19:32:20 by nige42           ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*line;
	size_t	index;
	size_t	len;

	index = 0;
	len = 0;
	if (!s1)
		len = (ft_strlen(s2) + 1);
	else
		len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	line = (char *)malloc(len * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	if (s1)
	{
		while (s1[index] != '\0')
		{
			line[index] = s1[index];
			index++;
		}
	}
	while (s2[len] != '\n')
		line[index++] = s2[len++];
	line[index] = '\0';
	return (line);
}

char	*get_chars(int fd)
{
	static char *line;
	char *temp;
	ssize_t nbytes;

	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	nbytes = read(fd, temp, BUFFER_SIZE);
	temp[nbytes + 1] = '\0';
	line = ft_strjoin(temp, "");
	printf("  1: --%zu -- ", nbytes);
	while (nbytes > 0)
	{
		printf("3: -%zu-", nbytes);
		if (ft_strchr(temp, '\n'))
			break;
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes < 1)
			break;
		temp[nbytes + 1] = '\0';
		line = ft_strjoin(line, temp);
		printf("2: -%zu-", nbytes);
	}

	return(line);
} 

char	*get_leftover(char *get_read)
{
	char	*found;
	char	*copy;
	static char	*leftover;
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

char	*get_next_line(int fd)
{
	
	char *get_read;
//	char *line;
//	static char *leftover;

	get_read = get_chars(fd);
//	line = ft_strjoin(leftover, get_read);
//	leftover = get_leftover(get_read);




	printf("\nget_read : %s",get_read);
//	printf("\nline              : %s ",line);
//	printf("\nleftover : %s ",leftover);

	return (get_read);
}
