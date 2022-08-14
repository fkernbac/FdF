/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:42:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/14 18:20:22 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**free_split(char **split)
{
	int	i;

	i = -1;
	while (split && split[++i])
		free(split[i]);
	// if (split)
	// 	free(split);
	return (NULL);
}

void	terminate(t_map *map)
{
	t_vert	*current;

	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	current = map->first;
	while (current)
		current = delete_vertex(current);
	free(map);
}
