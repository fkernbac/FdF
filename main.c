/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/14 18:19:17 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <fcntl.h>

void	setup_window(t_map *map)
{
	int		width;
	int		height;

	width = map->corner_r->x + 1;
	height = abs(map->highest->y) + abs(map->deepest->y) + 1;
	map->mlx = mlx_init(HEIGHT, WIDTH, "FdF", true);
	// if (map->mlx == NULL)
	// 	error(map);
	map->img = mlx_new_image(map->mlx, width, height);
	// if (map->img == NULL)
	// 	error(map);
	map->instance = mlx_image_to_window(map->mlx, map->img, \
		(WIDTH - width) / 2, (HEIGHT - height) / 2);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		return (EXIT_FAILURE);
	map = read_map(fd);
	close(fd);
	setup_map(map);
	setup_window(map);
	mlx_set_window_pos(map->mlx, 100, 300);
	draw_grid(map);
	mlx_key_hook(map->mlx, &keyhook, map);
	mlx_loop(map->mlx);
	terminate(map);
	return (EXIT_SUCCESS);
}
