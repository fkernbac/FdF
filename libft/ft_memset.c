/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:24 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 15:34:46 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//fills size bytes at pointer with value of content
void	*ft_memset(void *pointer, int content, size_t size)
{
	size_t			i;
	unsigned char	*byte;

	byte = (unsigned char *)pointer;
	i = 0;
	while (i < size)
	{
		byte[i] = (unsigned char)content;
		i++;
	}
	return (byte);
}
