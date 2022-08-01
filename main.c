/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/01 20:12:22 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <fcntl.h>

void	rotate_map(t_map *map)
{
	int		old;
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		old = current->x;
		current->x += map->last->y - current->y;
		current->y += old;
		current = current->next;
	}
}

void	squish_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->y *= 0.7;
		current = current->next;
	}
}

void	setup_window(t_map *map)
{
	t_vert	*current;
	int		width;
	int		height;

	width = map->row_end->x + 1;
	height = map->last->y + 1;
	map->mlx = mlx_init(HEIGHT, WIDTH, "FdF", true);
	if (map->mlx == NULL)
		exit(0);
	map->img = mlx_new_image(map->mlx, width, height);
	if (map->img == NULL)
		exit(0);
	map->instance = mlx_image_to_window(map->mlx, map->img, WIDTH / 2 - width / 2, HEIGHT / 2 - height / 2);
	current = map->first;
	while (current != NULL)
	{
		current->map = map;
		current = current->next;
	}
}

void	add_height(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->y -= current->z * 0.1;
		current = current->next;
	}
}

void	set_maxima(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current->right != NULL)
		current = current->right;
	map->row_end = current;
	current = map->first;
	while (current->down != NULL)
		current = current->down;
	map->col_end = current;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	close(fd);
	connect_vertices(map);
	set_maxima(map);
	rotate_map(map);
	standard_zoom(map, 10);
	add_height(map);
	// squish_map(map);
	set_original(map);
	setup_window(map);
	mlx_set_window_pos(map->mlx, 100, 300);
	center_map(map);
	draw_grid(map);
	mlx_key_hook(map->mlx, &keyhook, map);
	mlx_loop(map->mlx);
	// mlx_terminate(map->mlx);
	return (1);
}
