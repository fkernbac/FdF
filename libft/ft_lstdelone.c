/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 06:29:47 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 19:32:59 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//frees content of lst and lst
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
