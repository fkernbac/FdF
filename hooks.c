/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:03:21 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/01 20:02:48 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

// void	hook(void *param)
// {
// 	t_map	*map;

// 	map = param;
// 	// if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 	// 	mlx_close_window(map->mlx);
// 	if (mlx_is_key_down(param, MLX_KEY_UP))
// 		map->img->instances[0].y -= 5;
// 	// if (mlx_is_key_down(param, MLX_KEY_DOWN))
// 	// 	map->img->instances[0].y += 5;
// 	// if (mlx_is_key_down(param, MLX_KEY_LEFT))
// 	// 	map->img->instances[0].x -= 5;
// 	// if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// 	// 	map->img->instances[0].x += 5;
// }

//change zoom
void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map		*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(map->mlx);
		exit(1);
	}
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
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		zoom(map, 1);
		update_image(map, 1);
	}
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		zoom(map, 0);
		update_image(map, 0);
	}
}
