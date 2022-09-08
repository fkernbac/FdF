/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:55:27 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/08 20:02:03 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Draws wireframe grid onto image.
void	draw_grid(t_map *map)
{
	t_vert		*current;

	current = map->first;
	if (map->inactive_img)
		return (draw_grid(map->perspective));
	while (current != NULL)
	{
		if (current->right && current->x <= current->right->x)
			draw_line(current, current->right);
		else if (current->right)
			draw_line(current->right, current);
		if (current->up && current->x <= current->up->x)
			draw_line(current, current->up);
		else if (current->up)
			draw_line(current->up, current);
		current = current->next;
	}
	map->rev = -1;
}

//Draws grid from last to first vertex, so that front lines seem to be in front.
void	draw_rev_grid(t_map *map)
{
	t_vert	*current;

	current = map->last;
	if (map->inactive_img)
		return (draw_rev_grid(map->perspective));
	if (map->rev == 1)
		return (draw_grid(map));
	while (current != NULL)
	{
		if (current->right && current->x <= current->right->x)
			draw_line(current, current->right);
		else if (current->right)
			draw_line(current->right, current);
		if (current->up && current->x <= current->up->x)
			draw_line(current, current->up);
		else if (current->up)
			draw_line(current->up, current);
		current = current->prev;
	}
	map->rev = 1;
}

//Sets all vertices to completely opaque.
void	rm_transparency(t_map *map)
{
	t_vert		*current;
	uint32_t	opaque;

	opaque = 0x000000FF;
	current = map->first;
	while (current)
	{
		current->color = current->color | opaque;
		current = current->next;
	}
}

//Adds a transparency gradient to vertices.
void	add_transparency(t_map *map)
{
	t_vert		*current;
	double		step;

	current = map->first;
	if (map->last->row > 1)
		step = (double)255 / (double)(map->last->row + 1);
	else
		step = 0.8;
	if (map->inactive_img)
		add_transparency(map->perspective);
	rm_transparency(map);
	while (map->transp == -1 && current)
	{
		current->color -= (double)step * (double)current->row;
		current = current->next;
	}
	map->transp *= -1;
	if (map->inactive_img == NULL)
		img_update(map);
}
