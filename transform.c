/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:31:55 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/14 17:06:02 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	zoom(t_map *map, int in)
{
	t_vert	*current;
	int		factor;

	current = map->first;
	if (in == 1)
		map->zoom++;
	else
		map->zoom--;
	factor = pow(ZOOM, abs(map->zoom));
	while (map->zoom == 0 && current != NULL)
	{
		current->x = current->xo;
		current->y = current->yo;
		current->z = current->zo;
		current = current->next;
	}
	if (map->zoom == 0)
		return ;
	while (current != NULL && map->zoom > 0)
	{
		current->x = current->xo * factor;
		current->y = current->yo * factor;
		current->z = current->zo * factor;
		current = current->next;
	}
	while (current != NULL && map->zoom < 0)
	{
		current->x = current->xo / factor;
		current->y = current->yo / factor;
		current->z = current->zo / factor;
		current = current->next;
	}
}

void	translate(t_map *map, int x, int y)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->x += x;
		current->y += y;
		current = current->next;
	}
}

// void	center_map(t_map *map)
// {
// 	int		y_margin;
// 	int		x_margin;
// 	t_vert	*current;

// 	current = map->first;
// 	x_margin = map->img->width / 2 - (map->row_end->x - map->col_end->x) /2;
// 	y_margin = map->img->height / 2 - (map->last->y - map->first->y) / 2;
// 	while (current != NULL)
// 	{
// 		current->x += x_margin;
// 		current->y += y_margin;
// 		current = current->next;
// 	}
// }

void	center_map(t_map *map)
{
	const int	down = abs(map->deepest->y);
	t_vert		*current;

	current = map->first;
	while (current != NULL)
	{
		current->y += down;
		current = current->next;
	}
}
