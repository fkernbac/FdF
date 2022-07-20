/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:27:47 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 17:24:53 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//scans backwards for the first occurence of character in string
char	*ft_strrchr(const char *string, int character)
{
	int		i;

	i = ft_strlen(string);
	if (character == '\0')
		return ((char *)&string[i]);
	i--;
	while (i >= 0)
	{
		if (string[i] == (char)character)
			return ((char *)&string[i]);
		i--;
	}
	return (0);
}
