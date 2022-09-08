/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:42:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/08 20:10:59 by fkernbac         ###   ########.fr       */
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
	if (map == NULL)
		return ;
	if (map->mlx)
		mlx_terminate(map->mlx);
	if (map->perspective)
	{
		delete_list(map->perspective);
		free(map->perspective);
	}
	delete_list(map);
	free(map);
}

void	error(int e, t_map *map)
{
	if (e == 0)
		ft_printf("Invalid parameters");
	if (e == 1)
		perror("File error");
	if (e == 2)
		perror("Malloc error");
	if (e == 3)
		perror("Color format error");
	if (map != NULL)
		clean_memory(map);
	exit(EXIT_FAILURE);
}

void	terminate(t_map *map)
{
	if (map != NULL)
		clean_memory(map);
	exit(EXIT_SUCCESS);
}
