/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:46:08 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:26:00 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts the number of nodes in the list
int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*pointer;

	len = 1;
	pointer = lst;
	if (pointer == NULL)
		return (0);
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
		len++;
	}
	return (len);
}
