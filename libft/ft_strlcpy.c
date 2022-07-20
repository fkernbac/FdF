/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:49:50 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/02 23:49:50 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies size-1 chars from src to dest and returns length of src
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	length = ft_strlen((char *)src);
	if (size <= 0)
		return (length);
	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		if (dest[i] == 0)
			return (length);
		i++;
	}
	dest[i] = '\0';
	return (length);
}
