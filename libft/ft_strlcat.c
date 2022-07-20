/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:54:45 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:56 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies src to the '\0' of dest to the maximum dest[max - 1]
//returns length of the theoretically created string if creation started
size_t	ft_strlcat(char *dest, const char *src, size_t max)
{
	size_t	i;
	size_t	j;
	size_t	length_src;
	size_t	length_dest;

	length_src = ft_strlen((char *)src);
	length_dest = ft_strlen(dest);
	if (max == 0)
		return (length_src);
	if (length_dest > max)
		return (length_src + max);
	i = length_dest;
	j = 0;
	while (src[j] != '\0' && i < max - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (length_src + length_dest);
}
