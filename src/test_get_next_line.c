/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:30:46 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/18 10:47:39 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main(void)
{
	int fd;	
	char *ptr;

	fd = open("text.txt", O_RDONLY);
	if (!fd)
		return (write(1, "error",5));
	int i = 0;
	while ((ptr = get_next_line(fd)))
	{
	printf("\nOutput %i : %s", i, ptr);
		i++;
		free(ptr);
	}
	close(fd);
/*
	ptr = get_next_line(fd);
	printf("\noutput 1 :%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("\noutput 2 :%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("\noutput 3 :%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("\noutput 4 :%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("\noutput 5 :%s", ptr);
	free(ptr);


	ptr = get_next_line(fd);
	printf("\noutput 6 :%s", ptr);
	free(ptr);


	ptr = get_next_line(fd);
	printf("\noutput 7 :%s", ptr);
	free(ptr);


	ptr = get_next_line(fd);
	printf("\noutput 8 :%s\n", ptr);
	free(ptr);
*/
	close(fd);

	return (0);
}
