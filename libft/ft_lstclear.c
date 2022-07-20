/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:40:55 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:48:37 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//frees each node of the list starting at lst
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last != *lst)
		ft_lstclear(&(*lst)->next, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
