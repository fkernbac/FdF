/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:38:33 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/28 16:05:31 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//duplicates given string via malloc
char	*ft_strdup(const char *string)
{
	char			*duplicate;
	unsigned int	i;

	duplicate = malloc(ft_strlen((char *)string) + 1);
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		duplicate[i] = string[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
