/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/20 18:12:08 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <fcntl.h>

t_map	*read_map(int fd)
{
	char	*line;
	char	**split;
	t_map	*map;
	t_vert	*current;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = ft_calloc(1, sizeof(t_map));
	while (1)
	{
		line = get_next_line(fd, 10);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		if (split == NULL)
			return (NULL);
		while (split[x] != NULL)
		{
			if (x == 0 && y == 0)
			{
				current = new_vertex(x, y, ft_atoi(split[x]), NULL);
				map->first = current;
				x++;
			}
			current->right = new_vertex(x, y, ft_atoi(split[x]), current);
			current = current->right;
			map->x_max = x;
			x++;
		}
		x = 0;
		map->y_max = y;
		y++;
		free(line);
		free(split);
	}
	return (map);
}

void	draw_map(mlx_image_t *img, t_map *map)
{
	uint32_t	color;
	t_vert		*current;

	color = 0xFFFFFFFF;
	current = map->first;
	while (current != NULL)
	{
		mlx_put_pixel(img, current->x, current->y, color);
		current = current->right;
	}
}

void	rotate_map(t_map *map)
{
	int		old;
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		old = current->x;
		current->x += map->y_max - current->y;
		current->y += old;
		current = current->right;
	}
}

void	squish_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->y *= 1.5;
		current = current->right;
	}
}

void	draw_grid(mlx_image_t *img, t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		if (current->right != NULL)
			draw_line(current, current->right, img);
		if (current->up != NULL)
			draw_line(current, current->up, img);
		current = current->right;
	}
}

void	standard_zoom(t_map *map, int factor)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->x *= factor;
		current->y *= factor;
		current->z *= factor;
		current = current->right;
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 2)
		exit(0);
	//read map
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd);
	close(fd);
	//setup map
	connect_vertices(map);
	rotate_map(map);
	standard_zoom(map, 50);
	//draw window
	mlx = mlx_init(500, 500, "FdF", true);
	if (!mlx)
		exit(0);
	mlx_set_window_pos(mlx, 500, 500);
	//create content
	img = mlx_new_image(mlx, 1000, 1000);
	mlx_image_to_window(mlx, img, 100, 100);
	squish_map(map);
	draw_grid(img, map);
	draw_map(img, map);
	//run mlx
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (1);
}
