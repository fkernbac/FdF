/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:31:55 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/16 15:18:55 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Replaces old image by a scaled and translated version for new zoom level.
void	img_update_resize(t_map *map, int in)
{
	int	x;
	int	y;

	x = map->img->instances[0].x;
	y = map->img->instances[0].y;
	mlx_delete_image(map->mlx, map->img);
	ft_printf("map size: %ix%i\n", map->width, map->height);
	map->img = mlx_new_image(map->mlx, map->width, map->height + 1);
	if (map->img == NULL)
		error(2, map);
	draw_grid(map);
	mlx_image_to_window(map->mlx, map->img, x, y);
	if (in == 1)
	{
		map->img->instances[0].x = (4 * x - map->mlx->width) / 2;
		map->img->instances[0].y = (4 * y - map->mlx->height) / 2;
	}
	else
	{
		map->img->instances[0].x = (2 * x + map->mlx->width) / 4;
		map->img->instances[0].y = (2 * y + map->mlx->height) / 4;
	}
}

//Calculates new coordinates based on zoom level 0.
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

//Sets new map measurements based on zoom level.
void	resize_map(t_map *map)
{
	if (map->zoom > 0)
	{
		map->height = map->height_o * pow(ZOOM, map->zoom);
		map->width = map->width_o * pow(ZOOM, map->zoom);
	}
	else if (map->zoom < 0)
	{
		map->height = map->height_o / pow(ZOOM, abs(map->zoom));
		map->width = map->width_o / pow(ZOOM, abs(map->zoom));
	}
	else
	{
		map->height = map->height_o;
		map->width = map->width_o;
	}
}

//Resets map to zoom level 0.
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

//Calculates zoom, sets new map measurements and updates image.
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
	ft_printf("zoom level: %i\n", map->zoom);
	resize_map(map);
	img_update_resize(map, in);
}
