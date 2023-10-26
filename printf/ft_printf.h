#ifndef FT_PRINTF_H

#include <stdarg.h>

int	ft_printf(char const *str, ...);
int print_string(char *str);
int	print_char(char c);
int print_number(int num);
int	print_unsigned_number(unsigned int number);
int	print_perc();
int	print_hex(unsigned int num, int mayus);

#endif
