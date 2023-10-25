#include "libft.h"
#include "ft_printf.h"

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
	unsigned int num_aux;
	char str_num[20];

	len = 0;
	num_aux = number;
	while (num_aux != 0)
	{
		len++;
		num_aux = num_aux / 10;
	}
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

int	print_hex(int num, int mayus)
{
	int i;
	int	len;
	int num_aux;
	char str_num[11];
	char base[16];

	if (mayus)
		ft_strlcpy(base, "123456789ABCDEF", 16);
	else
		ft_strlcpy(base, "123456789abcdef", 16);
	i = 0;
	len = 0;
	num_aux = num;
	while (num_aux != 0)
	{
		len++;
		num_aux /= 10;
	}
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
