/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:33:42 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 14:50:41 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts number of characters in string excluding \0
size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	if (string == NULL)
		return (0);
	while (string[i] != '\0')
		i++;
	return (i);
}
