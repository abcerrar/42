/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:41:07 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/09 21:16:38 by dcolera-         ###   ########.fr       */
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

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	/*
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	*/
	free(line);
	close(fd);

	return (0);
}
