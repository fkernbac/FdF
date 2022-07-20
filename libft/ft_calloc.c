/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:04:03 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 14:57:57 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//allocates memory of number elements of size bytes and sets content to '\0'
void	*ft_calloc(size_t number, size_t size)
{
	char	*pointer;

	if (size != 0 && number > 18446744073709551615UL / size)
		return (NULL);
	pointer = malloc(number * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, number * size);
	return ((void *)pointer);
}
