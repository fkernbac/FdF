/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:12:58 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:12:31 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//allocates and copies values of original string until first delimiter
//string is duplicated and freed for clean up
static char	*fill_string(char *string, char limiter)
{
	char	*new_string;
	char	*clean_string;
	int		i;

	i = 0;
	new_string = (char *)ft_calloc(ft_strlen(string) + 1, 1);
	if (new_string == NULL)
		return (NULL);
	while (string[i] != limiter && string[i] != '\0')
	{
		new_string[i] = string[i];
		i++;
	}
	new_string[i] = '\0';
	clean_string = ft_strdup(new_string);
	free(new_string);
	return (clean_string);
}

//allocates every pointer in array with fill_string
//returns 1 if successful
static int	fill_array(char **array, const char *string,
	char limiter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string[i] != '\0')
	{
		while (string[i] == limiter && string[i] != '\0')
			i++;
		if (string[i] == '\0')
			break ;
		array[j] = fill_string((char *)(string + i), limiter);
		if (array[j] == NULL)
			return (0);
		while (string[i] != limiter && string[i] != '\0')
			i++;
		j++;
	}
	array[j] = NULL;
	return (1);
}

//returns the number of split strings
static size_t	count_splits(char const *string, char limiter)
{
	size_t			count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (string[i] != '\0')
	{
		while (string[i] == limiter && string[i] != '\0')
			i++;
		if (string[i] != '\0')
			count++;
		while (string[i] != limiter && string[i] != '\0')
			i++;
	}
	return (count);
}

//copies substrings divided by limiter into new array
char	**ft_split(char const *string, char limiter)
{
	char	**array;
	size_t	count;

	if (string == NULL)
		return (NULL);
	count = count_splits(string, limiter);
	if (count == 0)
	{
		array = ft_calloc(1, sizeof(char *));
		array[0] = NULL;
		return (array);
	}
	array = ft_calloc(count + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (fill_array(array, string, limiter) == 0)
	{
		free (array);
		return (NULL);
	}
	return (array);
}
