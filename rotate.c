/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:02:08 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/16 15:18:37 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Resets map to top view without height values.
void	flatten_map(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current)
	{
		current->x = current->xtop;
		current->y = current->ytop;
		current = current->next;
	}
}

//Calculates new coordinates starting at rotation 0.
void	calc_rotate(t_map *map, int steps)
{
	t_vert	*current;
	int		x;
	int		x_max;

	current = map->first;
	x_max = map->top_right->x;
	ft_printf("rotation level: %i\n", steps);
	while (steps > 0)
	{
		x = current->x;
		current->x = current->y;
		current->y = x_max - x;
		current = current->next;
		if (current == NULL)
		{
			steps--;
			current = map->first;
		}
	}
}

//Resets map, rotates, sets new original, and reapplies zoom and height.
void	rotate(t_map *map, int dir)
{
	map->rotation = (map->rotation + dir) % 4;
	if (map->rotation == -1)
		map->rotation = 3;
	flatten_map(map);
	calc_rotate(map, map->rotation);
	squish_map(map);
	set_height(map);
	set_original(map);
	if (map->zoom != 0)
		calc_zoom(map, pow(ZOOM, abs(map->zoom)));
	img_update(map);
}
