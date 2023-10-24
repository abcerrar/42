/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:10:49 by dcolera-          #+#    #+#             */
/*   Updated: 2023/09/26 01:34:38 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = (t_list *) malloc(1 * sizeof(t_list));
	if (!lista)
		return (NULL);
	lista -> content = content;
	lista -> next = NULL;
	return (lista);
}
