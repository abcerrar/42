#include "ft_printf.h"
#include "libft.h"

int	print_format(va_list args, char c)
{
	if (c == 'c')
		print_char(va_arg(args, int));
	if (c == 's')
		print_string(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		print_number(va_arg(args, int));
	if (c == 'u')
		print_unsigned_number(va_arg(args, unsigned int));

}

int	ft_printf(char const *str, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		if (str[i] == '%')
			print_format(args, str[i++ + 1]);
		i++;
	}

	va_end(args);
	return (ft_strlen(str));
}
