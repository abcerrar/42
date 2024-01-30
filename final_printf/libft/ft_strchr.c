/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:05:38 by dcolera-          #+#    #+#             */
/*   Updated: 2023/09/26 16:59:16 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*aux;

	if (c > 255)
		c = c % 256;
	aux = (char *)str;
	while (*aux != '\0')
	{
		if (*aux == (char)c)
			return (aux);
		aux++;
	}
	if (c == '\0')
		return (aux);
	return (NULL);
}
