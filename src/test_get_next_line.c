/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:30:46 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/05 21:15:21 by nige42           ###   ########.fr       */
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
		return (write(1, "error", BUFFER_SIZE));





	ptr = get_next_line(fd);
	printf("\n%s", ptr);


	ptr = get_next_line(fd);
	printf("\n%s", ptr);


	ptr = get_next_line(fd);
	printf("\n%s", ptr);

	return (0);
}
