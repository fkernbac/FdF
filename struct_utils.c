/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:47:22 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/24 17:04:01 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vert	*new_vertex(int x, int y, int z, t_vert *prev)
{
	t_vert	*new;

	new = ft_calloc(1, sizeof(t_vert));
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	new->prev = prev;
	new->left = NULL;
	new->right = NULL;
	new->up = NULL;
	new->down = NULL;
	new->row = y;
	new->col = x;
	return (new);
}

void	connect_vertices(t_map *map)
{
	t_vert	*current;
	t_vert	*above;

	current = map->first;
	above = current;
	while (current != NULL)
	{
		if (current->prev != NULL && current->row == current->prev->row)
		{
			current->left = current->prev;
			current->left->right = current;
		}
		if (current->y != 0)
		{
			current->up = above;
			above->down = current;
			above = above->next;
		}
		current = current->next;
	}
}
