/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:58:02 by dcolera-          #+#    #+#             */
/*   Updated: 2023/09/29 02:06:43 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	d = dst;
	s = src;
	if (d == s)
		return (dst);
	if (d > s)
	{
		i = (int)len;
		while (--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			d[i] = s[i];
	}
	return (dst);
}
