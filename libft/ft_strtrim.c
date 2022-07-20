/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:49:58 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:16:39 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks if c is element of string
static int	is_element_of(char const c, char const *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (c == string[i])
			return (1);
		i++;
	}
	return (0);
}

//returns exact length of trimmed sting
static int	trim_length(char const *string, char const *set)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (is_element_of(string[i], set) == 1 && string[i] != '\0')
		i++;
	while (string[i] != '\0')
	{
		len++;
		i++;
	}
	i--;
	while (is_element_of(string[i], set) == 1 && i > 0)
	{
		len--;
		i--;
	}
	return (len);
}

//removes characters defined in set from start and end of string
char	*ft_strtrim(char const *string, char const *set)
{
	char	*trimmed;
	int		i;

	if (string == NULL || set == NULL)
		return (NULL);
	i = 0;
	if (set[0] == '\0' || string[0] == '\0')
	{
		trimmed = ft_strdup(string);
		return (trimmed);
	}
	while (is_element_of(string[i], set) == 1 && string[i] != '\0')
		i++;
	trimmed = ft_substr(string, i, trim_length(string, set));
	return (trimmed);
}
