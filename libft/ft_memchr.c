/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:58:16 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 14:44:24 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//scans size bytes at pointer for target value
void	*ft_memchr(const void *pointer, int target, size_t size)
{
	size_t			i;
	unsigned char	*byte;

	byte = (unsigned char *)pointer;
	i = 0;
	while (i < size)
	{
		if (byte[i] == (unsigned char)target)
			return (byte + i);
		i++;
	}
	return (NULL);
}
