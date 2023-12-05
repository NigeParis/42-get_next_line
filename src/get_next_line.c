/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/05 17:14:05 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_memset(char *str, char c)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		str[i] = c;
		i++;
	}
}

char	*ft_strjoin(char *keep, char *str)
{
	int		i;	
	int		j;	
	int keep_size;
	char *temp;
	
	j = 0;
	keep_size = ft_strlen(keep);
	temp = malloc(keep_size + BUFFER_SIZE * sizeof(char));
	i = 0;
	while (keep[i] != '\0')
	{
		temp[i] = keep[i];
		i++;
	}
	while (j < BUFFER_SIZE)	
	{
		temp[i] = str[j];		
		j++;
		i++;
	}
	temp[i] = '\0';

	return (temp);
}

char	*get_next_line(int fd)
{
	
	char *ptr;
	char *keep;
	int	read_size;
	int	i;

	i = 0;
	keep = malloc((BUFFER_SIZE) * sizeof(char));
	if (!keep)
		return (0);
	ft_memset(keep, '\0');

	ptr = malloc((BUFFER_SIZE) * sizeof(char));
	if (!ptr)
		return (0);
	ft_memset(ptr, '\0');
	i = 0;
	read_size = read(fd, ptr, BUFFER_SIZE);
	while (ptr[i] != '\n')
	{
		i++;
		if(i == BUFFER_SIZE)
		{
			keep = ft_strjoin(keep, ptr);
			read_size = read(fd, ptr, BUFFER_SIZE);
			i = 0;
		}
	}
	free(ptr);
	return (keep);
}
