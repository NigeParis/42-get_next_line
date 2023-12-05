/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/05 22:34:10 by nige42           ###   ########.fr       */
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
	static char reserve[BUFFER_SIZE + 1];
	

	j = 0;
	keep_size = ft_strlen(keep);
	temp = malloc(keep_size + (BUFFER_SIZE) * sizeof(char));
	i = 0;

	while (reserve[i] != '\0')
	{
		temp[i] = reserve[i];
		i++;
	}

	
	while (keep[i] != '\0')
	{
		temp[i] = keep[i];
		i++;
	}
	while (j < BUFFER_SIZE && str[j] != '\n')	
	{
		temp[i] = str[j];		
		j++;
		i++;
	}
	temp[i] = '\0';
	i = j;
	while (i < BUFFER_SIZE)
	{
		reserve[i - j] = str[i];
		i++;
	}
	str[i - j] = '\0';
	return (temp);
}

int	found_newline(char *str)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}	
	return (0);
}






char	*get_next_line(int fd)
{
	
	static char *ptr;
	char *keep;

	keep = malloc(0);
	ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (*ptr != '\n')
	{
		read(fd, ptr, BUFFER_SIZE);

		keep = ft_strjoin(keep, ptr);
		if (found_newline(ptr))	
			break ;
		ptr++;
	}
	return (keep);
}
