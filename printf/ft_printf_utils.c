#include "ft_printf.h"

int	num_len(unsigned long num, int base, int is_long)
{
	int	len;

	if (!is_long)
		num = (unsigned int)num;
	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	size_t	str_len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = ft_strlen(str);
	write(1, str, str_len);
	return (str_len);
}

int	print_number(int num)
{
	char	*num_str;
	size_t	str_len;

	num_str = ft_itoa(num);
	print_string(num_str);
	str_len = ft_strlen(num_str);
	free(num_str);
	return (str_len);
}

int	print_unsigned_number(unsigned int number)
{
	int		i;
	int		len;
	char	str_num[20];

	len = num_len(number, 10, 0);
	i = len - 1;
	while (i >= 0)
	{
		str_num[i] = (number % 10) + 48;
		number /= 10;
		i--;
	}
	write(1, str_num, len);	
	return (len);
}

int	print_hex(unsigned long num, int mayus, int is_long)
{
	int		i;
	int		len;
	char	str_num[12];
	char	base[16];

	ft_strlcpy(base, "0123456789abcdef", 17);
	if (!is_long)
		num = (unsigned int)num;
	len = num_len(num, 16, is_long);
	i = len - 1;
	while (num != 0)
	{
		str_num[i] = base[(num % 16)];
		if (mayus)
			str_num[i] = ft_toupper(str_num[i]);
		num /= 16;
		i--;
	}
	write(1, str_num, len);
	return (len);
}

int	print_ptr(void *ptr)
{
	unsigned long	num_ptr;

	num_ptr = (unsigned long)ptr;
	write(1, "0x", 2);
	return (print_hex(num_ptr, 0, 1) + 2);
}
