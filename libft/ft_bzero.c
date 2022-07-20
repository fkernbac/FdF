/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:18:14 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 15:38:06 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//fills size bytes at pointer with '\0'
void	ft_bzero(void *pointer, size_t size)
{
	ft_memset(pointer, '\0', size);
}
