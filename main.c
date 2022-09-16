/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:09 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/16 15:07:26 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <fcntl.h>

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
}
