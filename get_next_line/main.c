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
	(void)argc;
	(void)argv;
	(void)line;

	/*
	fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	printf("Line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Line: %s", line);
	free(line);
	*/
	
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	//Test
	/*
	printf("\n------------------\nTests:\n");
	int count = 0;
	int lines = 0;
	char *res;

	fd = open("test.txt", O_RDONLY);
	do
	{
		res = get_next_line(fd);
		free(res);
		lines++;
	}while(res != NULL && lines< 20);
	close(fd);

	fd = open("test.txt", O_RDONLY);
	do
	{
		res = get_next_line(fd);
		free(res);
		if (res != NULL)
			count++;
	}while(res != NULL && count < 20);
	//printf("Lines: %d\n", lines);
	//printf("Count: %d\n", count);
	close(fd);
	*/

	return (0);
}
