/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:43:24 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/30 16:47:17 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Saves map coordinates to avoid rounding errors.
void	set_original(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->xo = current->x;
		current->yo = current->y;
		current = current->next;
	}
}

//Adds z value to grid and saves max und min y value.
void	set_height(t_map *map)
{
	t_vert	*current;

	current = map->first;
	map->highest = current;
	map->deepest = current;
	while (current != NULL)
	{
		current->y -= current->z * DEPTH;
		current->y += map->max_z * DEPTH;
		if (current->y > map->highest->y)
			map->highest = current;
		if (current->y < map->deepest->y)
			map->deepest = current;
		current = current->next;
	}
}

void	squish_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current)
	{
		current->y *= SQUISH;
		current = current->next;
	}
}

//Saves pointers to its neighbors into each vertex and saves corners in map.
void	connect_vertices(t_map *map)
{
	t_vert	*current;
	t_vert	*above;

	current = map->first;
	above = current;
	while (current != NULL)
	{
		current->map = map;
		if (current->prev != NULL && current->row == current->prev->row)
		{
			current->left = current->prev;
			current->left->right = current;
		}
		if (current->col == 0)
			map->bottom_left = current;
		if (current->row == 0)
			map->top_right = current;
		if (current->row != 0)
		{
			current->up = above;
			above->down = current;
			above = above->next;
		}
		current = current->next;
	}
}
