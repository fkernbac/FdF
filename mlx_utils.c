/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:08:15 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/01 20:46:25 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	is_visible(t_vert *vertex)
{
	mlx_image_t	*img;

	img = vertex->map->img;
	if (vertex != NULL && pixelcheck(vertex->x, vertex->y, vertex->color, img) == 1)
		return (1);
	if (vertex->up != NULL && pixelcheck(vertex->up->x, vertex->up->y, vertex->color, img) == 1)
		return (1);
	if (vertex->right != NULL && pixelcheck(vertex->right->x, vertex->right->y, vertex->color, img) == 1)
		return (1);
	// if (vertex != NULL && pixelcheck(vertex->down->x, vertex->down->y, vertex->color, img)
	// 	return (1);
	// if (vertex != NULL && pixelcheck(vertex->left->x, vertex->left->y, vertex->color, img)
	// 	return (1);
	return(0);
}

int	pixelcheck(int x, int y, uint32_t color, mlx_image_t *img)
{
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (0);
	mlx_put_pixel(img, x, y, color);
	return(1);
}

void	update_image(t_map *map, int in)
{
	int			x;
	int			y;

	x = map->img->instances[map->instance].x;
	y = map->img->instances[map->instance].y;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->row_end->x + 1, map->last->y + 1);
	if (map->img == NULL)
		exit(0);
	draw_grid(map);
	map->instance = mlx_image_to_window(map->mlx, map->img, x, y);
	if (in == 1)
	{
		map->img->instances[map->instance].x -= map->img->width / 4;
		map->img->instances[map->instance].y -= map->img->height / 4;
	}
	else
	{
		map->img->instances[map->instance].x += map->img->width / 2;
		map->img->instances[map->instance].y += map->img->height / 2;
	}
	ft_printf("%dx%d\n", map->img->width, map->img->height);
	mlx_put_pixel(map->img, 0, 0, 0xFF0000FF);
	mlx_put_pixel(map->img, 0, map->img->height - 1, 0xFF0000FF);
	mlx_put_pixel(map->img, map->img->width - 1, 0, 0xFF0000FF);
	mlx_put_pixel(map->img, map->img->width - 1, map->img->height - 1, 0xFF0000FF);
}

void	draw_grid(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		if (current->right != NULL)
			draw_line(current, current->right);
		if (current->up != NULL)
			draw_line(current, current->up);
		current = current->next;
		// while (current != NULL && is_visible(current) == 0)
			// current = current->next;
	}
}
