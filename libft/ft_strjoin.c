/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:33:54 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:16:06 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies first into result and returns index of terminating \0
static size_t	fill_first(char *result, char *first)
{
	int	i;
	int	index_result;

	i = 0;
	index_result = 0;
	while (first[i] != 0)
	{
		result[index_result] = first[i];
		i++;
		index_result++;
	}
	return (index_result);
}

//copies last into result starting at index_result
static size_t	fill_last(char *result, char *last, unsigned int index_result)
{
	int	i;

	i = 0;
	while (last[i] != '\0')
	{
		result[index_result] = last[i];
		i++;
		index_result++;
	}
	result[index_result] = '\0';
	return (index_result);
}

//combines strings first and last into new string
char	*ft_strjoin(char const *first, char const *last)
{
	char			*result;
	unsigned int	index_result;

	if (first == NULL || last == NULL)
		return (NULL);
	result = malloc(ft_strlen((char *)first) + ft_strlen((char *)last) + 1);
	if (result == NULL)
		return (NULL);
	index_result = fill_first(result, (char *)first);
	index_result = fill_last(result, (char *)last, index_result);
	if (result[index_result] == '\0')
		return (result);
	return (NULL);
}
