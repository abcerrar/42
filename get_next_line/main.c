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
	int fd2;
	char *line;
	char *line2;
	(void)argc;
	(void)argv;
	(void)line;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd2);
	printf("%s", line2);

	free(line);
	free(line2);

	close(fd);
	close(fd2);
	return (0);
}
