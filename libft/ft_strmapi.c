/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:33:51 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:16:23 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//applies f to each character of string and returns new string
char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (string == NULL)
		return (NULL);
	result = malloc(ft_strlen((char *)string) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (string[0] == '\0' || string == NULL)
	{
		result[0] = '\0';
		return (result);
	}
	while (string[i] != '\0')
	{
		result[i] = f(i, string[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
