/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:42:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/30 20:03:38 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**free_split(char **split)
{
	int	i;

	i = -1;
	while (split && split[++i])
		free(split[i]);
	if (split)
		free(split);
	return (NULL);
}

void	clean_memory(t_map *map)
{
	if (map->perspective)
	{
		delete_list(map->perspective);
		free(map);
	}
	mlx_terminate(map->mlx);
	delete_list(map);
	free(map);
}

void	error(int e, t_map *map)
{
	if (e == 1)
		perror("Error opening file");
	if (e == 2)
		perror("Malloc Error");
	if (map != NULL)
		clean_memory(map);
	system("leaks FdF");
	exit(EXIT_FAILURE);
}

void	terminate(t_map *map)
{
	if (map != NULL)
		clean_memory(map);
	system("leaks FdF");
	exit(EXIT_SUCCESS);
}
