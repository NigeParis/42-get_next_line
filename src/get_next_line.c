/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/12 07:14:40 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_chars(int fd, char *line)
{
	char 	*temp;
	int	 nbytes = 1;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(temp, '\n') && nbytes != 0)
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
	int 	len;
	
	index = 0;
	len = 0;
	if (get_read == NULL)
		return (NULL);
	len = ft_linelen(get_read);
	leftover = malloc((len + 2) * sizeof(char));
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
	return (leftover);
}


char	*ft_get_newline(char *get_read)
{
	char	*trimmed_read;
	int		i;
	int		len;



	i = 0;
	len = 0;
	if (!get_read)
		return (NULL);
	len = ft_linelen(get_read);
	trimmed_read = malloc((len + 1) * sizeof(char));
	if (!trimmed_read)
		return (NULL);
	while (get_read[i] != '\0')
	{
		trimmed_read[i] = get_read[i];
		if (trimmed_read[i] == '\n')
			break ;
		i++;
	}
	trimmed_read[i] = '\0';
	return (trimmed_read);
}


char	*get_next_line(int fd)
{
	
	static char *get_read;
	char *line;
	char *output;

	line = "";
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (0);
	get_read = get_chars(fd, line);
	if (!get_read)
		return (NULL);

	line = ft_getline(get_read);
	output = ft_get_newline(get_read);


/*

	printf("\n--get_read          : '%s'",get_read);
	printf("\n            --output: '%s'",output);
	printf("\n--line              : '%s'",line);
*/
	return (output);
}
