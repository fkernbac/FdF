/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:13:29 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:24:28 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns last node of the list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pointer;

	pointer = lst;
	if (pointer == NULL)
		return (NULL);
	while (pointer->next != NULL)
		pointer = pointer->next;
	return (pointer);
}
