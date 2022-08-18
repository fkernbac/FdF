/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:47:22 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/15 16:20:12 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vert	*new_vertex(int x, int y, int z, t_map *map)
{
	t_vert	*new;

	new = ft_calloc(1, sizeof(t_vert));
	if (new == NULL)
		error(2, map);
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = 0xFFFFFFFF;
	new->next = NULL;
	new->prev = NULL;
	new->left = NULL;
	new->right = NULL;
	new->up = NULL;
	new->down = NULL;
	new->row = y;
	new->col = x;
	return (new);
}

void	delete_list(t_map *map)
{
	t_vert	*first;
	t_vert	*second;

	first = map->first;
	second = first->next;
	while (second)
	{
		free(first);
		first = second;
		second = first->next;
	}
}
