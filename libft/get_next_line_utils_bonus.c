/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:19:02 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/11 16:40:32 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Frees pointer if allocated and returns null.
void	*free_and_null(void *pointer)
{
	if (pointer != NULL)
		free(pointer);
	pointer = NULL;
	return (NULL);
}

//Returns the index of the first linebreak or null in string.
size_t	newline_index(char *string)
{
	size_t	i;

	i = 0;
	if (string == NULL)
		return (0);
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	return (i);
}
