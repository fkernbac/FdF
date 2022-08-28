/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:02:08 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/27 15:53:39 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_coordinates(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current)
	{
		pixelcheck(current->x, current->y, 0xFF00FF, map->img);
		current = current->next;
	}
}

void	draw_image(t_map *map)
{
	pixelcheck(1, 1, 0xFF0000FF, map->img);
	pixelcheck(map->img->width - 1, 1, 0xFF0000FF, map->img);
	pixelcheck(1, map->img->height - 1, 0xFF0000FF, map->img);
	pixelcheck(map->img->width - 1, map->img->height - 1, 0xFF0000FF, map->img);
	pixelcheck(map->img->width / 2, map->img->height / 2, 0xFF0000FF, map->img);
}

void	update(t_map *map)
{
	int	x;
	int	y;

	x = map->img->instances[map->instance].x;
	y = map->img->instances[map->instance].y;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (map->img == NULL)
		error(2, map);
	// draw_coordinates(map);
	draw_grid(map);
	draw_image(map);
	map->instance = mlx_image_to_window(map->mlx, map->img, x, y);
}

void	flatten_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	// while (current && map->zoom > 0)
	// {
	// 	current->x = current->xtop * pow(ZOOM, abs(map->zoom));
	// 	current->y = current->ytop * pow(ZOOM, abs(map->zoom));
	// 	current = current->next;
	// }
	// while (current && map->zoom < 0)
	// {
	// 	current->x = current->xtop / pow(ZOOM, abs(map->zoom));
	// 	current->y = current->ytop / pow(ZOOM, abs(map->zoom));
	// 	current = current->next;
	// }
	// while (current && map->zoom == 0)
	while (current)
	{
		current->x = current->xtop;
		current->y = current->ytop;
		current = current->next;
	}
}

void	adjust_map(t_map *map)
{
	t_vert	*current;
	int		x_offset;
	int		y_offset;

	x_offset = 0;
	y_offset = 0;
	current = map->first;
	while (current)
	{
		if (current->x < x_offset)
			x_offset = current->x;
		if (current->y < y_offset)
			y_offset = current->y;
		current = current->next;
	}
	current = map->first;
	while (current)
	{
		current->x -= x_offset;
		// current->y -= y_offset;
		current = current->next;
	}
}

void	rotate(t_map *map, int dir)
{
	t_vert	*current;
	int		x;
	int		x_max;

	current = map->first;
	map->rotation = (map->rotation + dir) % 4;
	if (map->rotation == 1)
		map->rotation = -3;
	dir = map->rotation;
	ft_printf("rotation level %i\n", dir);
	flatten_map(map);
	x_max = map->top_right->x;
	while (dir < 0)
	{
		x = current->x;
		current->x = current->y;
		current->y = x_max - x;
		current = current->next;
		if (current == NULL)
		{
			dir++;
			current = map->first;
		}
	}
	squish_map(map);
	set_height(map);
	set_original(map);
	if (map->zoom != 0)
		calc_zoom(map, pow(ZOOM, abs(map->zoom)));
	update(map);
}
