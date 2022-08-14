/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:47:22 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/14 18:22:03 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_vert	*new_vertex(int x, int y, int z, char *color, t_vert *prev)
{
	t_vert	*new;

	new = ft_calloc(1, sizeof(t_vert));
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = str_to_color(color);
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

t_vert	*delete_vertex(t_vert *vertex)
{
	t_vert	*following;

	following = vertex->next;
	following->prev = NULL;
	following->left = NULL;
	if (vertex)
		free(vertex);
	return (following);
}
