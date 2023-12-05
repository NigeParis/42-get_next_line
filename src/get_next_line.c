/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/05 14:32:49 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


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



char	*get_next_line(int fd)
{
	
	char *ptr;
	int	read_size;
	int	i;

	i = 0;
	ptr = malloc((BUFFER_SIZE) * sizeof(char));
	if (!ptr)
		return (0);
	ft_memset(ptr, '\0');
	read_size = read(fd, ptr, BUFFER_SIZE);
	if (read_size < BUFFER_SIZE)
		printf("HELLO");







 
	return (ptr);
}
