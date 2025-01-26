/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:39:26 by ftroise           #+#    #+#             */
/*   Updated: 2023/02/06 20:15:10 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsecondlast(t_list *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*second_last;

	if (!lst || !*lst || !del)
		return ;
	while ((*lst)->next)
	{
		second_last = ft_lstsecondlast(*lst);
		ft_lstdelone(second_last->next, del);
		second_last->next = NULL;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
