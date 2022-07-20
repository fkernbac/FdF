/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:56:08 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 19:33:34 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//applies f to each node of the list and saves result in a new list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	if (lst->next != NULL)
	{
		new->next = ft_lstmap(lst->next, f, del);
		if (new->next == NULL)
		{
			ft_lstdelone(new, del);
			return (NULL);
		}
	}
	return (new);
}
