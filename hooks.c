/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:03:21 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/18 16:02:25 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Checks if another zoom would result in a too small or to big map.
int	check_zoom(t_map *map, int in)
{
	int	width;
	int	height;

	width = map->img->width;
	height = map->img->height;
	if (in == 1)
	{
		width *= ZOOM;
		height *= ZOOM;
	}
	else
	{
		width /= ZOOM;
		height /= ZOOM;
	}
	if (abs(width * height) >= 100000000 || width < 20 || height < 20)
		return (-1);
	return (1);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		terminate(map);
	if (keydata.key == MLX_KEY_W \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->img->instances[map->instance].y += 20;
	if (keydata.key == MLX_KEY_S \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->img->instances[0].y -= 20;
	if (keydata.key == MLX_KEY_D \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->img->instances[0].x -= 20;
	if (keydata.key == MLX_KEY_A \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->img->instances[0].x += 20;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS \
		&& check_zoom(map, 1) == 1)
		zoom(map, map->zoom + 1);
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS \
		&& check_zoom(map, 0) == 1)
		zoom(map, map->zoom - 1);
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		rotate(map, -1);
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		rotate(map, 1);
}
