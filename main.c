/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/08 20:21:49 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <fcntl.h>

void	setup_window(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (map->mlx == NULL)
		error(2, map);
	map->img = mlx_new_image(map->mlx, map->width, map->height + 1);
	if (map->img == NULL)
		error(2, map);
	draw_image(map);
	mlx_image_to_window(map->mlx, map->img, \
		(WIDTH - map->width) / 2, (HEIGHT - map->height) / 2);
}

int	pixelcheck(int x, int y, uint32_t color, mlx_image_t *img)
{
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (0);
	mlx_put_pixel(img, x, y, color);
	return (1);
}

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

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		error(0, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(1, NULL);
	map = read_map(fd);
	close(fd);
	if (map->first == NULL || map->first == map->last)
		error(1, map);
	setup_map(map);
	setup_window(map);
	draw_grid(map);
	mlx_key_hook(map->mlx, &keyhook, map);
	mlx_loop(map->mlx);
	terminate(map);
	return (EXIT_SUCCESS);
}
