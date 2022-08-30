/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:08:15 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/30 16:28:21 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	pixelcheck(int x, int y, uint32_t color, mlx_image_t *img)
{
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (0);
	mlx_put_pixel(img, x, y, color);
	return (1);
}

void	img_update(t_map *map)
{
	int	x;
	int	y;

	x = map->img->instances[map->instance].x;
	y = map->img->instances[map->instance].y;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (map->img == NULL)
		error(2, map);
	draw_grid(map);
	draw_image(map);
	map->instance = mlx_image_to_window(map->mlx, map->img, x, y);
}
