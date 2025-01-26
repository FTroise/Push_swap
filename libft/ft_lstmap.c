/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:55:56 by ftroise           #+#    #+#             */
/*   Updated: 2023/02/06 20:15:42 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_start;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	new_list = ft_lstnew(f(temp->content));
	if (!new_list)
		return (NULL);
	new_list_start = new_list;
	temp = temp->next;
	while (temp)
	{
		new_list->next = ft_lstnew(f(temp->content));
		if (!new_list->next)
		{
			ft_lstclear(&new_list_start, del);
			return (NULL);
		}
		new_list = new_list->next;
		temp = temp->next;
	}
	return (new_list_start);
}
