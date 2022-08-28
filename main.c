/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/27 18:44:42 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <fcntl.h>

void	setup_window(t_map *map)
{
	map->mlx = mlx_init(HEIGHT, WIDTH, "FdF", true);
	if (map->mlx == NULL)
		error(2, map);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (map->img == NULL)
		error(2, map);
	draw_image(map);
	map->instance = mlx_image_to_window(map->mlx, map->img, \
		(WIDTH - map->width) / 2, (HEIGHT - map->height) / 2);
}

//Draws the data of map on the image.
void	draw_grid(t_map *map)
{
	t_vert		*current;

	current = map->first;
	while (current != NULL)
	{
		if (current->right)
		{
			if (current->x <= current->right->x)
				draw_line(current, current->right);
			else
				draw_line(current->right, current);
		}
		if (current->up)
		{
			if (current->x <= current->up->x)
				draw_line(current, current->up);
			else
				draw_line(current->up, current);
		}
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		error(1, NULL);
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
