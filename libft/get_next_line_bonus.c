/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 02:32:03 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/11 20:28:16 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds empty bytes at the end of string and frees old string.
char	*add_empty(char *string, int BUFFER_SIZE)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_calloc(ft_strlen(string) + BUFFER_SIZE + 1, 1);
	if (new == NULL)
		return (NULL);
	if (string == NULL)
		return (new);
	while (string[i] != '\0')
	{
		new[i] = string[i];
		i++;
	}
	free(string);
	return (new);
}

//Copies string to new string without trailing empty bytes.
char	*remove_empty(char *string)
{
	size_t	i;
	char	*duplicate;

	i = 0;
	duplicate = ft_calloc(ft_strlen(string) + 1, 1);
	while (string[i] != '\0')
	{
		duplicate[i] = string[i];
		i++;
	}
	return (duplicate);
}

//Searches string for a line and returns it if found.
char	*get_line(char *string, int check, size_t newline)
{
	char	*trimmed;
	size_t	i;

	i = 0;
	if (string == NULL)
		return (NULL);
	if (string[newline] == '\n')
	{
		trimmed = ft_calloc(newline + 1 + 1, 1);
		if (trimmed == NULL)
			return (NULL);
		while (i <= newline)
		{
			trimmed[i] = string[i];
			i++;
		}
		return (trimmed);
	}
	if (check == 0)
		return (remove_empty(string));
	return (NULL);
}

//Calculates the string for static saving.
char	*get_static_string(char *string, int check, size_t newline)
{
	size_t	i;
	char	*trimmed;

	if (string == NULL || check == 0 || string[0] == '\0')
		return (free_and_null(string));
	if (string[newline] == '\n')
	{
		i = 0;
		if (string[newline + 1] == '\0')
			return (free_and_null(string));
		trimmed = ft_calloc(ft_strlen(string + newline) + 1, 1);
		if (trimmed == NULL)
			return (NULL);
		while (string[newline + 1 + i] != '\0')
		{
			trimmed[i] = string[newline + 1 + i];
			i++;
		}
		free(string);
		return (trimmed);
	}
	return (string);
}

//Reads file and returns its content until the next linebreak or end of file.
char	*get_next_line(int fd, int BUFFER_SIZE)
{
	static char	*saved[1025];
	char		*line;
	int			check;
	size_t		newline;

	line = NULL;
	newline = newline_index(saved[fd]);
	line = get_line(saved[fd], 1, newline);
	saved[fd] = get_static_string(saved[fd], 1, newline);
	while (line == NULL)
	{
		saved[fd] = add_empty(saved[fd], BUFFER_SIZE);
		check = read(fd, saved[fd] + ft_strlen(saved[fd]), BUFFER_SIZE);
		if (check < 0 || saved[fd][0] == '\0')
		{
			saved[fd] = free_and_null(saved[fd]);
			return (NULL);
		}
		newline = newline_index(saved[fd]);
		line = get_line(saved[fd], check, newline);
		saved[fd] = get_static_string(saved[fd], check, newline);
	}
	return (line);
}
