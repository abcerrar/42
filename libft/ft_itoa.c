/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:04:37 by dcolera-          #+#    #+#             */
/*   Updated: 2023/09/29 01:41:56 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_num(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	n2;

	if (n == 0)
		return (ft_strdup("0"));
	len = len_num(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	n2 = n;
	if (n < 0)
	{
		n2 *= -1;
		str[0] = '-';
	}
	str[len] = 0;
	while (n2 > 0)
	{
		len--;
		str[len] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	return (str);
}
