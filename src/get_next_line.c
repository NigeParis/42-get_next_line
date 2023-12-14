/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/14 11:37:57 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_chars(int fd)
{
	char	*line;
	char 	temp[BUFFER_SIZE + 1];
	ssize_t	 nbytes = 1;
	char *tmp = NULL;


	line = "";
	temp[0] = '\0';
	while (nbytes > 0)
	{
		if (ft_strchr(temp, '\n'))
			break;
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			return (NULL);
		}
		temp[nbytes] = '\0';
		if (line)
		{
			tmp  = ft_realloc(line, temp);
			line = ft_strdup(tmp);
			free(tmp);}
		
	}
	return(line);
} 

char	*get_leftover(char *leftover, char *get_read)
{

	int i;
	int j;

	i = 0;
	while (get_read[i] && get_read[i] != '\n')
		i++;
	if (get_read[i] == '\n')
		i++;
	
	j = 0;
	while (get_read[i])
	{
		leftover[j] = get_read[i];
		i++;
		j++;
	}
	leftover[j] = '\0';
	
	return (leftover);
}


char	*get_line_trim(char *get_read, char *leftover)
{
	char	*trimmed_read;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!*get_read)
		return (NULL);
	while (get_read[len] && get_read[len] != '\n')
		len++;

	trimmed_read = malloc(len + 2 * sizeof(char));
	while (i < len)
	{
		trimmed_read[i] = get_read[i];
		i++;
	}
	if (get_read[i] == '\n')
	{
		trimmed_read[i] = '\n';
		trimmed_read[i + 1] = '\0';
	}
	else	
		trimmed_read[i] = '\0';
	i = 0;
	

	if (len < BUFFER_SIZE)
	{
		len++;
		while (get_read[len])
			leftover[i++] = get_read[len++];
		leftover[i] = '\0';
	}
	return (trimmed_read);
}


char	*get_next_line(int fd)
{
	
	char *get_read;
	char *line;
	char *output;
	char *ptr_leftover;
	static char leftover[BUFFER_SIZE + 2];

	ptr_leftover = leftover;

	if ((fd <= 0 || BUFFER_SIZE <= 0) || (read(fd, NULL, 0) < 0))
		return (0);

	get_read = get_chars(fd);
	line = ft_strjoin(ptr_leftover, get_read);
	ptr_leftover = get_leftover(ptr_leftover, line);
	output = get_line_trim(line, leftover);


	if ((read(fd, NULL, 0) == 0) && (*line == '\0'))
	{
		*ptr_leftover = 0;
		return(NULL);
	}

	free(get_read);
	free(line);
	return (output);
}
