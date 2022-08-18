/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:53:27 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/18 16:33:50 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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
		if (current->x == 0)
			map->corner_l = current;
		if (current->y == 0)
			map->corner_r = current;
		if (current->y != 0)
		{
			current->up = above;
			above->down = current;
			above = above->next;
		}
		current = current->next;
	}
}

//Rotates for isometric perspective.
void	rotate_map(t_map *map)
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

// //Sets up map to fit the window.
void	zoom_for_window(t_map *map)
{
	int		dis_x;
	int		dis_y;
	int		factor;
	t_vert	*current;

	dis_x = (HEIGHT - 1) / map->corner_r->x;
	dis_y = (WIDTH - 1) / map->last->y;
	if (dis_x < 2)
		dis_x = 2;
	if (dis_y < 2)
		dis_y = 2;
	if (dis_x > dis_y)
		factor = dis_x;
	else
		factor = dis_y;
	current = map->first;
	while (current != NULL)
	{
		current->x *= factor;
		current->xtop = current->x;
		current->y *= factor;
		current->ytop = current->y;
		current->z *= factor;
		current = current->next;
	}
}

//Adds z value to grid, squishes map and saves max und min y value.
void	set_height(t_map *map)
{
	t_vert	*current;

	current = map->first;
	map->highest = current;
	map->deepest = current;
	while (current != NULL)
	{
		current->y -= current->z * DEPTH;
		current->y *= SQUISH;
		if (current->y > map->highest->y)
			map->highest = current;
		if (current->y < map->deepest->y)
			map->deepest = current;
		current = current->next;
	}
}

//Formats data inside map and saves result as base for transformations.
void	setup_map(t_map *map)
{
	t_vert	*current;
	int		adjust_y;

	connect_vertices(map);
	rotate_map(map);
	zoom_for_window(map);
	set_height(map);
	current = map->first;
	adjust_y = abs(map->deepest->y);
	map->width = map->corner_r->x;
	map->height = abs(map->deepest->y) + abs(map->highest->y);
	while (current != NULL)
	{
		current->y += adjust_y;
		current->ytop += adjust_y;
		current->xo = current->x;
		current->yo = current->y;
		current = current->next;
	}
}
