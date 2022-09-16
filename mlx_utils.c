/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:07:06 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/16 15:07:56 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Creates the MLX window.
void	setup_window(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (map->mlx == NULL)
		error(2, map);
	map->img = mlx_new_image(map->mlx, map->width, map->height + 1);
	if (map->img == NULL)
		error(2, map);
	mlx_image_to_window(map->mlx, map->img, \
		(WIDTH - map->width) / 2, (HEIGHT - map->height) / 2);
}

//Checks if filled pixel is part of image.
int	pixelcheck(int x, int y, uint32_t color, mlx_image_t *img)
{
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (0);
	mlx_put_pixel(img, x, y, color);
	return (1);
}

//Empties image and draws new map.
void	img_update(t_map *map)
{
	mlx_image_t	*img;

	img = map->img;
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	if (map->rev == -1)
		draw_grid(map);
	else
	{
		map->rev = -1;
		draw_rev_grid(map);
	}
}
