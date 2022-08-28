/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:04:02 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/28 21:16:58 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	copy_grid(t_map *old, t_map *new)
{
	t_vert	*original;
	t_vert	*copy;
	t_vert	*prev;
	int		dis;
	int		y_offset;

	dis = 5;
	y_offset = 0;
	original = old->first;
	prev = NULL;
	while (original)
	{
		copy = new_vertex(original->col * dis, original->row * dis, original->z, new);
		// ft_printf("(%i|%i|%i) ", copy->x, copy->y, copy->z);
		// copy->y = copy->y - copy->z + y_offset;
		// copy->y = copy->y + copy->z;
		copy->color = original->color;
		copy->row = original->row;
		copy->col = original->col;
		copy->map = new;
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

t_map	*persp_map(t_map *map)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	new->mlx = map->mlx;
	new->img = mlx_new_image(map->mlx, map->mlx->width, map->mlx->height);
	if (new == NULL || new->img == NULL)
		error(2, map);
	copy_grid(map, new);
	ft_printf("copied vertices.\n");
	connect_vertices(new);
	ft_printf("connected vertices.\n");
	return (new);
}

//is perspective growth with limit? limit being the horizon
// void	perspective_y(t_map *map)
// {
// 	t_vert	*current;
// 	int		horizon;
// 	int		max_row;
// 	double	factor;

// 	horizon = map->mlx->height / 2;
// 	max_row = map->last->row;
// 	factor = -0.2;
// 	current = map->last;
// 	while (current)
// 	{
// 		// current->y = horizon - (horizon - current->y) * exp(factor * (max_row - current->row));
// 		// current->y = current->y * (1  log(1 + max_row - current->row));
// 		current = current->prev;
// 	}
// }

void	projection(t_map *map)
{
	t_vert	*current;
	// int		x;
	// int		y;
	int		y_of_image_plane;
	int		eye_x;
	int		eye_z;
	//		eye_y = - y_of_image_plane

	y_of_image_plane = 700;
	eye_x = 600;
	eye_z = 600;
	current = map->first;
	while (current)
	{
		//row1: 400 + ((100 - 400)		*	(100			/	(0			+ 100))) = 400 + (-300 * 1) = 100
		//row2: 400 + ((100 - 400)		*	(100			/	(100 + 100))) = 400 + (-300 * (100/200)) = 400 + (-150) = 250;
		// ft_printf("%i + %i --- ", eye_x, (current->x - eye_x) * y_of_image_plane / (current->y + y_of_image_plane));
		current->x = eye_x + ((current->x - eye_x) * y_of_image_plane / (current->y + y_of_image_plane));
		current->y = eye_z + ((current->z - eye_z) * y_of_image_plane / (current->y + y_of_image_plane));
		// ft_printf("(%i|%i)\n", x, y);
		// pixelcheck(x, y, 0xFFFF00FF, map->img);
		current = current->next;
	}
}

void	perspective(t_map *map)
{
	map->img->instances[map->instance].enabled = 0;
	map->img2 = map->img;
	if (map->perspective == NULL)
	{
		map->perspective = persp_map(map);
		ft_printf("built map. first vertex is %i\n", map->perspective->first->z);
		// perspective_y(map->perspective);
		projection(map->perspective);
		draw_grid(map->perspective);
		ft_printf("drew map.\n");
		map->img = map->perspective->img;
		mlx_image_to_window(map->mlx, map->img, 0, 0);
	}
}
