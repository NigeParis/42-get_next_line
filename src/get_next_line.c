/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:29:01 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/11 19:11:40 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}




char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	index;
	size_t	len;

	index = 0;
	len = 0;
	if (!s1)
		len = (ft_strlen(s2) + 1);
	else
		len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = (char *)malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	len = 0;
	while (s1[index] != '\0')
	{
		result[index] = s1[index];
		index++;
	}
	while (s2[len] != '\0')
		result[index++] = s2[len++];
	result[index] = '\0';
	return (result);
}



char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	find;
	int				i;

	find = (unsigned char)c;
	str = (char *)s;
	i = 0;
	if (find == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (str[i])
	{
		if (find == str[i])
			return (&str[i]);
		i++;
	}
	return (NULL);
}


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
//	free(temp);
//	free(line);
	printf("\nline : %s",line);
	return(line);
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
	leftover = malloc((leftover_size + 1) * sizeof(char));
	while (i < leftover_size)
	{
		leftover[i] = *copy;
		i++;
		copy++;
	}
	leftover[i] = '\0';
//	free (get_read);

	printf("left %s", leftover);
	return (leftover);
}


char	*get_line_trim(char *get_read)
{
	char	*trimmed_read;
	int		i;
	int		len;



	i = 0;
	if (!get_read)
		return (NULL);
	len = ft_strlen(get_read);
	printf("\ntrim g_read %d",len);	

	trimmed_read = malloc((len + 2) * sizeof(char));
	i = 0;
	while (get_read[i] != '\0')
	{
		trimmed_read[i] = get_read[i];
		i++;
		if (trimmed_read[i] == '\n')
			break ;
	}
	trimmed_read[i] = '\n';
	i++;
	trimmed_read[i] = '\0';
	

	len = ft_strlen(trimmed_read);
	printf("\ntrim end_read %d",len);	

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
	line = "";
	get_read = get_chars(fd, line);
	if (!get_read)
		return (NULL);
	line = ft_strjoin(leftover, get_read);
	printf("\nget_read 2 here :%s", get_read);
	leftover = get_leftover(get_read);
	printf("\nline 3 here :%s", line);
	output = get_line_trim(line);

//	free(get_read);
//	get_read = NULL;
//	free(line);
//	line = NULL;
	printf("\n--get_read          : '%s'",get_read);
	printf("\n            --output: '%s'",output);
	printf("\n--line              : '%s'",line);
	printf("\n--leftover          : '%s'",leftover);

	return (output);
}
