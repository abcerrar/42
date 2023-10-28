#include "ft_printf.h"

int	print_format(va_list args, char c, int total_length)
{
	total_length -= 2;
	if (c == 'c')
		total_length += print_char(va_arg(args, int));
	else if (c == 's')
		total_length += print_string(va_arg(args, char *));
	else if (c == 'p')
		total_length += print_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		total_length += print_number(va_arg(args, int));
	else if (c == 'u')
		total_length += print_unsigned_number(va_arg(args, unsigned int));
	else if (c == '%')
		total_length += print_char('%');
	else if (c == 'x')
		total_length += print_hex(va_arg(args, unsigned int), 0, 0);
	else if (c == 'X')
		total_length += print_hex(va_arg(args, unsigned int), 1, 0);
	return (total_length);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		total_length;
	va_list	args;

	total_length = ft_strlen(str);
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		if (str[i] == '%')
			total_length = print_format(args, str[i++ + 1], total_length);
		i++;
	}
	va_end(args);
	return (total_length); 
}
