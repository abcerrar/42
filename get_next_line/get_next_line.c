/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:32:58 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/12 03:26:36 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

char	*buffer_format(char *buffer)
{
	char	*buff2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	buff2 = (char *)malloc(ft_strlen(buffer) - i);
	if (!buff2)
		return (free(buffer), NULL);
	while (buffer[++i])
		buff2[j++] = buffer[i];
	buff2[j] = 0;
	free(buffer);
	return (buff2);
}

char	*line_format(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	len = i;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = buffer[i];
	line[i] = 0;
	return (line);
}

char	*get_buffline(int fd, char *buffer)
{
	char	*new_buffer;
	int		bytes_read;

	if (contains(buffer, '\n') != -1)
		return (buffer);
	new_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, new_buffer, BUFFER_SIZE);
		//not buffer free
		if (bytes_read == -1)
		{
			free(new_buffer);
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		new_buffer[bytes_read] = 0;
		buffer = ft_strjoin(buffer, new_buffer);
		if (!buffer)
		{
			free(new_buffer);
			free(buffer);
			return (NULL);
		}
		//printf("Buffer: -%s-", buffer);
		if (contains(buffer, '\n') != -1)
			break;
	}
	free(new_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	//printf("fd: %d\n", fd);
	//printf("Read code: %ld\n", read(fd, 0, 0));
	if (buffer && read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return(NULL);
		buffer[0] = 0;
	}
	buffer = get_buffline(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = line_format(buffer);
	buffer = buffer_format(buffer);
	return (line);
}
