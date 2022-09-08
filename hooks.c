/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:03:21 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/08 18:28:54 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Sets limits on possible zoom values.
int	check_size(t_map *map, int in)
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
	if (abs(width * height) >= 200000000 || width < 50 || height < 50)
		return (-1);
	return (1);
}

//Switches between isometric (1) and perspective (2) projection.
void	switch_projection(t_map *map, int nr)
{
	if (nr == 1 && map->inactive_img != NULL)
	{
		map->img = map->inactive_img;
		map->inactive_img = NULL;
		map->img->instances[0].enabled = 1;
		map->perspective->img->instances[0].enabled = 0;
	}
	else if (nr == 2 && map->inactive_img == NULL)
	{
		map->img->instances[0].enabled = 0;
		map->inactive_img = map->img;
		create_perspective(map);
		map->perspective->img->instances[0].enabled = 1;
		map->img = map->perspective->img;
	}
}

//Handles translation (WASD).
int	hook_translate(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_W)
		map->img->instances[0].y += 20;
	else if (keydata.key == MLX_KEY_S)
		map->img->instances[0].y -= 20;
	else if (keydata.key == MLX_KEY_D)
		map->img->instances[0].x -= 20;
	else if (keydata.key == MLX_KEY_A)
		map->img->instances[0].x += 20;
	else
		return (0);
	return (1);
}

//Handles zoom (Q, E) and rotation (Z, X) functions.
int	hook_zoom_rota(mlx_key_data_t keydata, t_map *map)
{
	if (map->inactive_img != NULL)
		return (0);
	else if (keydata.key == MLX_KEY_Q && check_size(map, 1) == 1)
		zoom(map, map->zoom + 1);
	else if (keydata.key == MLX_KEY_E && check_size(map, 0) == 1)
		zoom(map, map->zoom - 1);
	else if (keydata.key == MLX_KEY_X)
		rotate(map, -1);
	else if (keydata.key == MLX_KEY_Z)
		rotate(map, 1);
	else
		return (0);
	return (1);
}

//Relays user input to the right functions.
void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.action == MLX_REPEAT)
		hook_translate(keydata, map);
	else if (keydata.action != MLX_PRESS)
		return ;
	else if (keydata.key == MLX_KEY_ESCAPE)
		terminate(map);
	else if (hook_translate(keydata, map) == 1)
		return ;
	else if (hook_zoom_rota(keydata, map) == 1)
		return ;
	else if (keydata.key == MLX_KEY_1)
		switch_projection(map, 1);
	else if (keydata.key == MLX_KEY_2)
		switch_projection(map, 2);
	else if (keydata.key == MLX_KEY_R)
		draw_rev_grid(map);
	else if (keydata.key == MLX_KEY_T)
		add_transparency(map);
}
