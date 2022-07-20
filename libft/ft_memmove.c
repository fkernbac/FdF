/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:18:07 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 15:33:58 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks sequence of adresses dest, src to handle overlapping
//then copies size bytes from src to dest
void	*ft_memmove(void *dest, const void *src, size_t size)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (dest);
	if (src < dest)
	{
		i = (int)size - 1;
		while (i >= 0)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)size)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
