/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:53:27 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/14 18:01:03 by fkernbac         ###   ########.fr       */
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
		else
		{
			current->up = above;
			above->down = current;
			above = above->next;
		}
		current = current->next;
	}
}

//Saves top right and bottom left corner vertices in map.
// void	set_corners(t_map *map)
// {
// 	t_vert	*current;

// 	current = map->first;
// 	while (current->right != NULL)
// 		current = current->right;
// 	map->corner_r = current;
// 	current = map->first;
// 	while (current->down != NULL)
// 		current = current->down;
// 	map->corner_l = current;
// }

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

// //Sets up map to fit the window.
void	fit_to_window(t_map *map)
{
	int		dis_x;
	int		dis_y;
	int		factor;
	t_vert	*current;

	dis_x = (HEIGHT - 1) / map->corner_r->x;
	dis_y = (WIDTH - 1) / map->last->y;
	if (dis_x < 1)
		dis_x = 1;
	if (dis_y < 1)
		dis_y = 1;
	if (dis_x > dis_y)
		factor = dis_x;
	else
		factor = dis_y;
	current = map->first;
	while (current != NULL)
	{
		current->x *= factor;
		current->y *= factor;
		current->z *= factor;
		current = current->next;
	}
}

//Squishes for isometric perspective.
// void	squish_map(t_map *map)
// {
// 	t_vert	*current;

// 	current = map->first;
// 	while (current != NULL)
// 	{
// 		current->y *= SQUISH;
// 		current = current->next;
// 	}
// }

//Saves original coordinates into each vertex.
// void	set_original(t_map *map)
// {
// 	t_vert	*current;

// 	current = map->first;
// 	while (current != NULL)
// 	{
// 		current->xo = current->x;
// 		current->yo = current->y;
// 		current->zo = current->z;
// 		current = current->next;
// 	}
// }

//Searches for lowest and highest y coordinate.
// void	get_height(t_map *map)
// {
// 	t_vert	*current;

// 	current = map->first;
// 	map->highest = current;
// 	map->deepest = current;
// 	while (current != NULL)
// 	{
// 		if (current->y > map->highest->y)
// 			map->highest = current;
// 		if (current->y < map->deepest->y)
// 			map->deepest = current;
// 		current = current->next;
// 	}
// }

//Formats data inside map and saves result as base for transformations.
void	setup_map(t_map *map)
{
	t_vert	*current;

	connect_vertices(map);
	rotate_map(map);

	set_height(map);
	fit_to_window(map);
	current = map->first;
	while (current != NULL)
	{
		current->xo = current->x;
		current->yo = current->y;
		current->zo = current->z;
		current = current->next;
	}
}
