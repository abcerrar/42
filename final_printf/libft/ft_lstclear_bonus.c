/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:23:41 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 18:19:53 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	aux = *lst;
	while (aux)
	{
		aux = aux->next;
		del(tmp->content);
		free(tmp);
		tmp = aux;
	}
	*lst = NULL;
}
