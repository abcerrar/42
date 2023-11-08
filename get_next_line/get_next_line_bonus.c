/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:32:58 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 19:46:27 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_buffer(char **buffer, char **str2)
{
	free(*buffer);
	*buffer = NULL;
	if (str2)
		free(*str2);
	return (NULL);
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
	if (buff2)
	{
		while (buffer[++i])
			buff2[j++] = buffer[i];
		buff2[j] = 0;
	}
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
		if (bytes_read == -1)
			return (free_buffer(&buffer, &new_buffer));
		if (bytes_read == 0)
			break ;
		new_buffer[bytes_read] = 0;
		buffer = ft_strjoin(buffer, new_buffer);
		if (!buffer)
			return (free_buffer(&buffer, &new_buffer));
		if (contains(new_buffer, '\n') != -1)
			break ;
	}
	free(new_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10];
	char		*line;

	if (buffer[fd] && read(fd, 0, 0) < 0)
		return (free_buffer(&buffer[fd], NULL));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = (char *)malloc(1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = 0;
	}
	buffer[fd] = get_buffline(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (!buffer[fd][0])
		return (free_buffer(&buffer[fd], NULL));
	line = line_format(buffer[fd]);
	if (!line)
		return (free_buffer(&buffer[fd], NULL));
	buffer[fd] = buffer_format(buffer[fd]);
	return (line);
}
