/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:04:02 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/30 17:24:18 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vert	*copy_vertex(t_vert *original)
{
	t_vert	*copy;
	int		dis;

	dis = (original->map->mlx->width * 2) / (original->map->last->col + 1);
	copy = new_vertex(original->col, original->row, original->z, original->map->perspective);
	copy->color = original->color;
	copy->row = original->row;
	copy->col = original->col;
	copy->map = original->map->perspective;
	copy->x *= dis;
	copy->y *= dis;
	return (copy);
}

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

void	transparency(t_map *map)
{
	t_vert	*current;
	double	transparency;

	transparency = 256 / map->last->row;
	current = map->first;
	while (current)
	{
		if (transparency * current->row >= 256)
			current->color -= transparency * (current->row - 0.5);
		else
		current->color -= transparency * current->row;
		current = current->next;
	}
}

void	project_perspective(t_map *map)
{
	t_vert	*current;
	int		y_of_image_plane;
	int		eye_x;
	int		eye_z;

	y_of_image_plane = 700;
	eye_x = map->img->width / 2;
	eye_z = map->img->height - (map->img->height / 3);
	current = map->first;
	while (current)
	{
		current->x = eye_x + ((current->x - eye_x) * y_of_image_plane / (current->y + y_of_image_plane));
		current->y = eye_z + ((current->z - eye_z) * y_of_image_plane / (current->y + y_of_image_plane));
		current = current->next;
	}
}

void	mirror(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current)
	{
		current->y = map->img->height - current->y - 1;
		current->x = map->img->width - current->x - 1;
		current = current->next;
	}
}

void	create_perspective(t_map *map)
{
	if (map->perspective != NULL)
		return ;
	map->perspective = malloc(sizeof(t_map));
	map->perspective->mlx = map->mlx;
	map->perspective->img = mlx_new_image(map->mlx, map->mlx->width * 2, map->mlx->height);
	if (map->perspective == NULL || map->perspective == NULL)
		error(2, map);
	copy_grid(map, map->perspective);
	connect_vertices(map->perspective);
	transparency(map->perspective);
	project_perspective(map->perspective);
	mirror(map->perspective);
	draw_grid(map->perspective);
	mlx_image_to_window(map->mlx, map->perspective->img, -1 * map->mlx->width / 2, 0);
}
