/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 02:30:53 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 18:20:16 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	int		i;

	if (dstsize == 0)
		return (ft_strlen(src));
	len_src = ft_strlen(dst);
	i = -1;
	if (dstsize <= len_src)
		return (ft_strlen(src) + dstsize);
	while (src[++i] && (len_src + i) < (dstsize - 1))
		dst[len_src + i] = src[i];
	dst[len_src + i] = 0;
	return (ft_strlen(src) + len_src);
}
