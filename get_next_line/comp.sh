#!/bin/bash

if [ $# -ge 2 ] && [ "$2" = "san" ]; then
	cc -D BUFFER_SIZE=$1 -Wall -Wextra -Werror -fsanitize=address -g main.c get_next_line.c get_next_line_utils.c
	exit 1
fi
	cc -D BUFFER_SIZE=$1 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
