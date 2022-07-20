/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:19:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 16:40:48 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks if big at index equals little
static int	check_substring(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (big[i] == little[i] && big[i] != '\0' && i < len)
	{
		i++;
		if (little[i] == '\0')
			return (1);
	}
	return (0);
}

//scans len characters of big for first occurence of little
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (check_substring(big + i, little, len - i) == 1)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
