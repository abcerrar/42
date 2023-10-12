/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:41:07 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/12 02:40:35 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	
	int fd;
	char *line;
	fd = open("test.txt", O_RDWR);
	(void)argc;
	(void)argv;

	/*
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	*/
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	free(line);
	close(fd);

	return (0);
}
