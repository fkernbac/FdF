/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:50:19 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:24:08 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//applies f to the content of each node of the list
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pointer;

	pointer = lst;
	if (lst == NULL)
		return ;
	while (pointer != NULL)
	{
		f(pointer->content);
		pointer = pointer->next;
	}
}
