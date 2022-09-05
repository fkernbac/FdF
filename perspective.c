/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:04:02 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/05 15:09:56 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Copies vertex without isometric transformations.
t_vert	*copy_vertex(t_vert *original)
{
	t_vert	*copy;
	int		dis;

	dis = original->map->width_o / (original->map->last->col + 1);
	copy = new_vertex(original->col, original->row, original->z, \
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
	int		y_of_image_plane;
	int		eye_x;
	int		eye_z;

	y_of_image_plane = map->mlx->height * 1.3;
	eye_x = map->width / 2;
	eye_z = map->mlx->height - (map->mlx->height / 3);
	current = map->first;
	while (current)
	{
		current->x = eye_x + ((current->x - eye_x) * \
			y_of_image_plane / (current->y + y_of_image_plane));
		current->y = eye_z + ((current->z - eye_z) * \
			y_of_image_plane / (current->y + y_of_image_plane));
		current = current->next;
	}
}

//Mirrors map from top left to bottom right corner.
void	mirror(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current)
	{
		current->y = map->img->height - current->y;
		current->x = map->img->width - current->x - 1;
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
	map->perspective->height = map->mlx->height;
	copy_grid(map, map->perspective);
	connect_vertices(map->perspective);
	map->perspective->width = map->perspective->last->x + 1;
	map->perspective->img = mlx_new_image(map->mlx, map->perspective->width, map->mlx->height);
	project_perspective(map->perspective);
	mirror(map->perspective);
	draw_rev_grid(map->perspective);
	draw_image(map->perspective);
	mlx_image_to_window(map->mlx, map->perspective->img, (map->mlx->width - map->perspective->width) / 2, 0);
}
