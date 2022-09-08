/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:04:02 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/08 20:02:46 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Copies vertex without isometric transformations.
t_vert	*copy_vertex(t_vert *original)
{
	t_vert	*copy;
	int		dis;

	dis = original->map->width_o / (original->map->last->col + 1);
	copy = new_vertex(original->col, original->row, original->z * DEPTH, \
		original->map->perspective);
	copy->color = original->color;
	copy->row = original->row;
	copy->col = original->col;
	copy->map = original->map->perspective;
	copy->x *= dis;
	copy->y *= dis;
	return (copy);
}

//Copies the original vertex list into new map.
void	copy_grid(t_map *old, t_map *new)
{
	t_vert	*original;
	t_vert	*copy;
	t_vert	*prev;

	original = old->first;
	prev = NULL;
	while (original)
	{
		copy = copy_vertex(original);
		copy->prev = prev;
		if (prev != NULL)
			prev->next = copy;
		else
			new->first = copy;
		prev = copy;
		original = original->next;
	}
	new->last = prev;
}

//Transforms 3D coordinates into 2D plane projection coordinates.
void	project_perspective(t_map *map)
{
	t_vert	*current;
	int		eye_x;
	int		eye_z;

	current = map->first;
	map->highest = current;
	map->deepest = current;
	eye_x = map->width / 2;
	eye_z = map->mlx->height - map->mlx->height * 0.2;
	while (current)
	{
		current->x = eye_x + ((current->x - eye_x) * \
			EYE_D / (current->y + EYE_D));
		current->y = eye_z + ((current->z - eye_z) * \
			EYE_D / (current->y + EYE_D));
		if (current->y > map->highest->y)
			map->highest = current;
		if (current->y < map->deepest->y)
			map->deepest = current;
		current = current->next;
	}
}

//Adjusts image coordinates and mirrors map.
void	mirror_adjust(t_map *map)
{
	t_vert	*current;
	int		adjust_y;

	current = map->first;
	adjust_y = -1 * map->deepest->y;
	while (current)
	{
		current->y += adjust_y;
		current = current->next;
	}
	map->height = map->highest->y + 1;
	current = map->first;
	while (current)
	{
		current->y = map->height - current->y - 1;
		current->x = map->width - current->x - 1;
		current = current->next;
	}
}

//Creates a second map in perspective projection.
void	create_perspective(t_map *map)
{
	if (map->perspective != NULL)
		return ;
	map->perspective = init_map();
	if (map->perspective == NULL)
		error(2, map);
	map->perspective->mlx = map->mlx;
	map->perspective->width = map->width_o;
	map->perspective->height = map->height_o;
	copy_grid(map, map->perspective);
	connect_vertices(map->perspective);
	map->perspective->width = map->perspective->last->x + 1;
	project_perspective(map->perspective);
	mirror_adjust(map->perspective);
	map->perspective->img = mlx_new_image \
		(map->mlx, map->perspective->width, map->perspective->height);
	draw_rev_grid(map->perspective);
	draw_image(map->perspective);
	mlx_image_to_window(map->mlx, map->perspective->img, \
		(map->perspective->width - map->mlx->width) / -2, \
		map->mlx->height - map->perspective->height);
}
