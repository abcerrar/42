#include "libft.h"
#include "ft_printf.h"

int num_len(unsigned int num, int base)
{
	int len;

	len = 0;
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

int	print_perc()
{
	write(1, "%", 1);
	return (1);
}

int print_string(char *str)
{
	size_t str_len;

	str_len = ft_strlen(str);
	write(1, str, str_len);
	return (str_len);
}

int print_number(int num)
{
	char *num_str;
	size_t str_len;

	num_str = ft_itoa(num);
	print_string(num_str);
	str_len = ft_strlen(num_str);
	free(num_str);
	return (str_len);
}

int	print_unsigned_number(unsigned int number)
{
	int i;
	int len;
	char str_num[20];

	len = num_len(number, 10);
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

int	print_hex(unsigned int num, int mayus)
{
	int i;
	int	len;
	char str_num[20];
	char base[16];

	if (mayus)
		ft_strlcpy(base, "123456789ABCDEF", 16);
	else
		ft_strlcpy(base, "123456789abcdef", 16);
	len = num_len(num, 16);
	i = len - 1;
	while (num != 0)
	{
		str_num[i] = base[(num % 16) - 1];
		num /= 16;
		i--;
	}
	write(1, str_num, len);
	return (len);
}
