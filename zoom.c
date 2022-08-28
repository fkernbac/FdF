/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:31:55 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/27 16:01:25 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	update_image(t_map *map, int in)
{
	int	x;
	int	y;

	x = map->img->instances[map->instance].x;
	y = map->img->instances[map->instance].y;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (map->img == NULL)
		error(2, map);
	draw_image(map);
	draw_grid(map);
	map->instance = mlx_image_to_window(map->mlx, map->img, x, y);
	if (in == 1)
	{
		map->img->instances[map->instance].x = (4 * x - map->mlx->width) / 2;
		map->img->instances[map->instance].y = (4 * y - map->mlx->height) / 2;
	}
	else if (in == -1)
	{
		map->img->instances[map->instance].x = (2 * x + map->mlx->width) / 4;
		map->img->instances[map->instance].y = (2 * y + map->mlx->height) / 4;
	}
}

void	calc_zoom(t_map *map, int factor)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL && map->zoom > 0)
	{
		current->x = current->xo * factor;
		current->y = current->yo * factor;
		current = current->next;
	}
	while (current != NULL && map->zoom < 0)
	{
		current->x = current->xo / factor;
		current->y = current->yo / factor;
		current = current->next;
	}
}

void	resize_map(t_map *map)
{
	if (map->zoom > 0)
	{
		map->height = map->height_o * pow(ZOOM, map->zoom);
		map->width = map->width_o * pow(ZOOM, map->zoom);
	}
	else if (map->zoom < 0)
	{
		map->height = map->height_o / pow(ZOOM, map->zoom);
		map->width = map->width_o / pow(ZOOM, map->zoom);
	}
	else
	{
		map->height = map->height_o;
		map->width = map->width_o;
	}
}

void	reset_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->x = current->xo;
		current->y = current->yo;
		current = current->next;
	}
}

void	zoom(t_map *map, int level)
{
	int		factor;
	int		in;

	in = -1;
	if (map->zoom < level)
		in = 1;
	map->zoom += in;
	factor = pow(ZOOM, abs(map->zoom));
	if (map->zoom == 0)
		reset_map(map);
	else
		calc_zoom(map, factor);
	resize_map(map);
	update_image(map, in);
}
