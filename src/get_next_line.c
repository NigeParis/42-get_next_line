/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/12 10:19:41 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_chars(int fd)
{
	char	*line;
	char 	*temp;
	char 	*tmp;
	ssize_t	 nbytes = 1;


	line = "";
	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while (nbytes > 0)
	{
		if (ft_strchr(temp, '\n'))
			break;
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (!nbytes)
		{
			free(temp);
			return (NULL);
		}
		line = ft_strjoin(line, temp);
		
	}
	free(temp);
	temp = NULL;
	tmp = ft_strjoin("", line);
	free(line);

	return(tmp);
} 

char	*get_leftover(char *get_read)
{
	char	*found;
	char	*copy;
	char	*leftover;
	int		leftover_size;	
	int 	i;	
	
	i = 0;
	leftover_size = 0;
	found = ft_strchr(get_read, '\n');
	found++;
	copy = found;
	while (*found)
	{
		found++;
		leftover_size++;
	}
	leftover = malloc(leftover_size * sizeof(char));
	while (i < leftover_size)
	{
		leftover[i] = *copy;
		i++;
		copy++;
	}
	leftover[leftover_size] = '\0';
//	free (get_read);
	return (leftover);
}


char	*get_line_trim(char *get_read)
{
	char	*trimmed_read;
	int		i;	

	i = 0;
	while (get_read[i] != '\n')
		i++;
	trimmed_read = malloc(i + 1 * sizeof(char));
	i = 0;
	while (get_read[i] != '\n')
	{
		trimmed_read[i] = get_read[i];
		i++;
	}
	trimmed_read[i] = '\n';
	i++;
	trimmed_read[i] = '\0';
	
//	free(get_read);		
	return (trimmed_read);
}


char	*get_next_line(int fd)
{
	
	char *get_read;
	char *line;
	char *output;
	static char *leftover;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (0);
	get_read = get_chars(fd);
	if (!get_read)
		return (NULL);
	line = ft_strjoin(leftover, get_read);
	leftover = get_leftover(get_read);
	output = get_line_trim(line);

	free(get_read);
	get_read = NULL;
	free(line);
	line = NULL;
/*	printf("\n--get_read          : '%s'",get_read);
	printf("\n            --output: '%s'",output);
	printf("\n--line              : '%s'",line);
	printf("\n--leftover          : '%s'",leftover);
*/
	return (output);
}
