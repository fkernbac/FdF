/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:12:32 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:16:43 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//calculates length of substring
//if return value > 0 substring creation is not possible
static int	substr_length(size_t strlen, unsigned int start, size_t maxlen)
{
	int	difference;

	difference = (int)strlen - start;
	if (difference < (int) maxlen)
		return (difference);
	return (maxlen);
}

//copies substring from index start to new string
char	*ft_substr(char const *string, unsigned int start, size_t maxlen)
{
	char			*substring;
	int				len;
	unsigned int	i;

	if (string == NULL)
		return (NULL);
	i = 0;
	len = substr_length(ft_strlen((char *)string), start, maxlen);
	if (len <= 0)
	{
		substring = malloc(1);
		substring[0] = '\0';
		return (substring);
	}
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < maxlen && string[start] != '\0')
	{
		substring[i] = string[start];
		start++;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
