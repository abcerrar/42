/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:14:44 by dcolera-          #+#    #+#             */
/*   Updated: 2023/09/26 17:00:11 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*aux;

	if (c > 255)
		c = c % 256;
	aux = NULL;
	while (*str != '\0')
	{
		if (*str == (char) c)
			aux = (char *)str;
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (aux);
}
