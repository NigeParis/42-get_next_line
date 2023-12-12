/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/12 08:50:48 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_chars(int fd, char *line)
{
	char 	*temp;
	int	 nbytes;
	


	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	nbytes = 1;
	printf("XX\n");
	while (!ft_strchr(line, '\n') && nbytes != 0)
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[nbytes] = '\0';
		line = ft_strjoin(line, temp);
		
	}
	return(line);
}





int	ft_linelen(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = 0;
	while(line[len] && line[len] != '\n')
	{
		len++;
	}
	return (len);
}

char	*ft_getline(char *get_read)
{
	char	*leftover;
	int 	index;
	int		readlen;

	index = 0;
	readlen = ft_linelen(get_read);
	if (get_read == NULL)
		return (NULL);
	leftover = malloc((readlen + 2) * sizeof(char));
	if (!leftover)
		return (NULL);
	while (get_read[index] && get_read[index] != '\n')
	{
		leftover[index] = get_read[index];
		index++;
	}
	if (get_read[index] == '\n')
	{
		leftover[index] = get_read[index];
		index++;
	}
	leftover[index] = '\0';

	printf("\nleft %s", leftover);
	return (leftover);
}


char	*ft_get_new_line(char *get_read)
{
	char	*trimmed_read;
	int		i;
	int		len;
	int		readlen;


	
	i = 0;
	len = 0;
	readlen = ft_strlen(get_read);
	if (!get_read)
		return (NULL);
	len = ft_linelen(get_read);
	trimmed_read = malloc((readlen - len + 1) * sizeof(char));
	if (!trimmed_read)
		return (NULL);
	while (get_read[len] != '\0')
	{
		trimmed_read[i] = get_read[len];
		i++;
		len++;
	}
	trimmed_read[len] = '\0';
	printf("\ntrim %s", trimmed_read);
	return (trimmed_read);
}





char	*get_next_line(int fd)
{
	
	char *line;
	static char *get_read;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	get_read = get_chars(fd, get_read);
	if (!get_read)
		return (NULL);
	line = ft_getline(get_read);
	get_read = ft_get_new_line(get_read);
	printf("line : %s",line);

/*

	printf("\n--get_read          : '%s'",get_read);
	printf("\n            --output: '%s'",output);
	printf("\n--line              : '%s'",line);
*/
//	return (line);
	return (get_read);
}
