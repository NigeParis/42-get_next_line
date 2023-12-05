/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/05 13:52:54 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>






char	*get_next_line(int fd)
{
	
	char *ptr;
	int	read_size;
	int	i;

	i = 0;
	ptr = malloc((BUFFER_SIZE) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < BUFFER_SIZE)
	{
		ptr[i] = '\0';
		i++;
	}
	read_size = read(fd, ptr, BUFFER_SIZE); 
//	printf("--%d--", read_size);
	return (ptr);

}
