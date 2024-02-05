/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:43 by dcolera-          #+#    #+#             */
/*   Updated: 2024/01/29 19:49:00 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(unsigned long num, int base, int is_long);
int	print_number(int num);
int	print_unsigned_number(unsigned int number);
int	print_hex(unsigned long num, int mayus, int is_long);
int	print_ptr(void *ptr);

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
	else
		total_length += print_char(c);
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
			total_length = print_format(args, str[++i], total_length);
		i++;
	}
	va_end(args);
	return (total_length);
}
