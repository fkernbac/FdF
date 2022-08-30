/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:53:27 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/30 17:07:47 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Rotates for isometric perspective.
void	isometric_rotate(t_map *map)
{
	int		old;
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		old = current->x;
		current->x += map->last->y - current->y;
		current->y += old;
		current = current->next;
	}
}

//Sets up map to fit the window.
void	scale_to_window(t_map *map)
{
	int		dis_x;
	t_vert	*current;

	dis_x = WIDTH / map->top_right->x;
	if (dis_x < 4)
		dis_x = 4;
	current = map->first;
	while (current != NULL)
	{
		current->x *= dis_x;
		current->xtop = current->x;
		current->y *= dis_x;
		current->ytop = current->y;
		current->z *= dis_x;
		current = current->next;
	}
}

//Sets an image size for map at zoom 0.
void	measure_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	map->max_z = 0;
	map->min_z = 0;
	while (current != NULL)
	{
		if (current->z > map->max_z)
			map->max_z = current->z;
		if (current->z < map->min_z)
			map->min_z = current->z;
		current = current->next;
	}
	map->width = map->top_right->x;
	map->width_o = map->width;
	map->height = map->last->y + abs(map->min_z) * DEPTH + abs(map->max_z) * DEPTH;
	map->height_o = map->height;
}

//Formats data inside map and saves result as base for transformations.
void	setup_map(t_map *map)
{
	connect_vertices(map);
	isometric_rotate(map);
	scale_to_window(map);
	squish_map(map);
	measure_map(map);
	set_height(map);
	set_original(map);
}
