/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/07 10:31:02 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strjoin(char *keep, char *str)
{
	int			i;	
	int			j;	
	int			keep_size;
	char		*temp;
	static char	reserve[BUFFER_SIZE];
	
	keep_size = 0;
	j = 0;
	if (keep)
		keep_size = ft_strlen(keep);
	temp = malloc((keep_size + (BUFFER_SIZE)) * sizeof(char));
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
	free(keep);
	return (temp);
}



char	*get_next_line(int fd)
{
	
	static char *ptr;
	char *keep;
	ssize_t r;
	int i;

	i = 0;
	keep = malloc(BUFFER_SIZE * sizeof(char));
	ptr = malloc(BUFFER_SIZE * sizeof(char));
	if (!ptr)
		return (0);
	r = read(fd, ptr, (BUFFER_SIZE));
	keep = ft_strjoin(keep, ptr);
	while (*ptr != '\n')
	{
	
		r = read(fd, ptr, (BUFFER_SIZE));
		
		printf(" -- %zu -- ", r);
		keep = ft_strjoin(keep, ptr);
		if (found_newline(ptr) || r == 0)
			break ;
		ptr++;
		i++;
	}

	return (keep);
}
