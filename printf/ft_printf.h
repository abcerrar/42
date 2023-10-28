#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(char const *str, ...);
int	print_string(char *str);
int	print_char(char c);
int	print_number(int num);
int	print_unsigned_number(unsigned int number);
int	print_hex(unsigned long num, int mayus, int is_long);
int	print_ptr(void *ptr);

#endif
