/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:30:46 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/08 15:20:26 by nrobinso         ###   ########.fr       */
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

	ptr = get_next_line(fd);
//	printf("\n%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
//	printf("\n%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
//	printf("\n%s", ptr);
	free(ptr);
/*
	ptr = get_next_line(fd);
	printf("\n%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("\n%s", ptr);
	free(ptr);
*/
	return (0);
}
