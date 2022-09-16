/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:01:59 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/12 17:21:24 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Prints out height value of each vertex.
void	print_coordinates(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		if (current->right == NULL)
			ft_printf("%i ", current->z);
		current = current->next;
	}
}

//Paints coordinate pixels without lines.
void	draw_coordinates(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current)
	{
		pixelcheck(current->x, current->y, 0xFF00FF, map->img);
		current = current->next;
	}
}

//Paints pixels in each corner of the image.
void	draw_image(t_map *map)
{
	pixelcheck(1, 1, 0xFF0000FF, map->img);
	pixelcheck(map->img->width - 1, 1, 0xFF0000FF, map->img);
	pixelcheck(1, map->img->height - 1, 0xFF0000FF, map->img);
	pixelcheck(map->img->width - 1, map->img->height - 1, 0xFF0000FF, map->img);
	pixelcheck(map->img->width / 2, map->img->height / 2, 0xFF0000FF, map->img);
}
