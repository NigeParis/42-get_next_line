/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:30:46 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/19 07:02:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main(void)
{
	int fd[2];	
	char *ptr;

	fd[0] = open("text.txt", O_RDONLY);
	if (!fd[0])
		return (write(1, "error",5));


	fd[1] = open("text2.txt", O_RDONLY);
	if (!fd[1])
		return (write(1, "error",5));
	int i = 0;
	int j = 0;


	while ((ptr = get_next_line(fd[j])))
	{
	printf("\nOutput file %d %i : %s", j, i, ptr);
		i++;
		free(ptr);
		if (j == 1)
			j = 0;
		else
			j = 1;
	}
	close(fd[0]);
	close(fd[1]);
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

	return (0);
}
