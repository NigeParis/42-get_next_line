/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:30:46 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/05 13:57:17 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int strjoin(char *ptr)
{
	int i;

	i = 0;
	while(ptr[i])
	{
		i++;
	}

	return (i);
}






int	main(void)
{
	int fd;	
	int i;	
	char *ptr;

	i = -1;
	fd = open("text.txt", O_RDONLY);
	if (!fd)
		return (write(1, "error", BUFFER_SIZE));


	ptr = get_next_line(fd);

	while (*ptr != '\0')
	{
		while (i < BUFFER_SIZE - 1)
		{
			i++;
			if (ptr[i] != '\0')
				printf("%c", ptr[i]);
		}
		ptr = get_next_line(fd);
		i = -1;
	}


	return (0);
}
