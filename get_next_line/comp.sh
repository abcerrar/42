#!/bin/bash

if [ $# -ge 2 ] && [ "$2" = "san" ]; then
	cc -D BUFFER_SIZE=$1 -Wall -Wextra -Werror -fsanitize=address -g main.c get_next_line.c get_next_line_utils.c
	exit 1
elif [ $# -ge 2 ] && [ "$2" = "bonus" ]; then
	cc -D BUFFER_SIZE=$1 -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c
	exit 1
elif [ $# -ge 2 ] && [ "$2" = "bonussan" ]; then
	cc -D BUFFER_SIZE=$1 -Wall -Wextra -Werror -fsanitize=address -g main.c get_next_line_bonus.c get_next_line_utils_bonus.c
	exit 1
fi
	cc -D BUFFER_SIZE=$1 -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
