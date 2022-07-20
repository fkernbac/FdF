/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:47:22 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/20 15:15:51 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vert	*new_vertex(int x, int y, int z, t_vert *left)
{
	t_vert	*new;

	new = ft_calloc(1, sizeof(t_vert));
	new->x = x;
	new->y = y;
	new->z = z;
	new->left = left;
	new->right = NULL;
	new->up = NULL;
	new->down = NULL;
	return (new);
}

void	connect_vertices(t_map *map)
{
	t_vert	*current;
	t_vert	*above;

	current = map->first;
	above = current;
	while (current->y == 0)
		current = current->right;
	while (current != NULL)
	{
		current->up = above;
		above->down = current;
		above = above->right;
		current = current->right;
	}
}
