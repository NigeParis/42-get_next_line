/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/12 17:22:57 by nrobinso         ###   ########.fr       */
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
	temp = malloc(BUFFER_SIZE + 1 * sizeof(char *));
	temp[0] = '\0';
	while (nbytes > 0)
	{
		if (ft_strchr(temp, '\n'))
			break;
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[nbytes] = '\0';
		line = ft_strjoin(line, temp);
		
	}
	free(temp);
	temp = NULL;
	tmp = ft_strjoin("", line);

	return(tmp);
} 

char	*get_leftover(char *get_read)
{

	char *leftover;
	int i;
	int j;
	int len = 0;

	i = 0;
//	printf("\nget_read  LFO: %s", get_read);
	len = ft_strlen(get_read);
	if (!*get_read && len == 1)
		return (printf("EXIT"),NULL);

	while (get_read[i] && get_read[i] != '\n')
		i++;
	i++;
//	printf("\ni:::%d--len-%d",i, len);
	leftover = malloc(((len - i) + 1) * sizeof(char *));
	j = 0;
	while (i < len + 1)
	{
		leftover[j] = get_read[i];
		i++;
		j++;
	}
	leftover[j] = '\0';
//	printf("\n LEFTOVER --------------------------------%s",leftover);	
	return (leftover);
}


char	*get_line_trim(char *get_read)
{
	char	*trimmed_read;
	int		i;	

	i = 0;
	if (!*get_read)
		return (NULL);
	while (get_read[i] && get_read[i] != '\n')
		i++;
	trimmed_read = malloc(i + 2 * sizeof(char *));
	i = 0;
	while (get_read[i] != '\n')
	{
		trimmed_read[i] = get_read[i];
		i++;
	}
	trimmed_read[i] = '\n';
	i++;
	trimmed_read[i] = '\0';
	
	return (trimmed_read);
}


char	*get_next_line(int fd)
{
	
	char *get_read;
	char *line;
	char *output;
	static char *leftover;

	if ((fd <= 0 || BUFFER_SIZE <= 0))
		return (0);
	get_read = get_chars(fd);
	line = ft_strjoin(leftover, get_read);
//	printf("\n--line 1             : '%s'\n",line);
	leftover = get_leftover(get_read);
//	printf("\n--leftover 1          : '%s'",leftover);
	output = get_line_trim(line);
	if ((read(fd, NULL, 0) == 0) && (*line == '\0'))
	{
//		printf("DDDD");
		return(NULL);
	}

//	printf("\n            --output Source: '%s'",output);

	free(get_read);
	get_read = NULL;
	free(line);
	line = NULL;
/*
	printf("\n--get_read          : '%s'",get_read);
	printf("\n            --output: '%s'",output);
	printf("\n--line              : '%s'",line);
	printf("\n--leftover          : '%s'",leftover);
*/
	return (output);
}
