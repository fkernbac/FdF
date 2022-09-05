/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:47:22 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/02 16:27:06 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Formats given channel values as RGBA value.
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

//Returns integer value of decimal or hexadecimal character.
int	ctoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

//Interprets given string as RGBA value.
int	str_to_color(char *str, t_map *map)
{
	int	len;
	int	color;

	color = 0xFFFFFFFF;
	if (str == NULL)
		return (color);
	len = ft_strlen(str);
	if (str[0] != '0' && str[1] != 'x')
		error(3, map);
	if (len == 4)
		color = get_rgba(0, 0, ctoi(str[2]) * 16 + ctoi(str[3]), 255);
	else if (len == 6)
		color = get_rgba(0, ctoi(str[2]) * 16 + ctoi(str[3]), \
			ctoi(str[4]) * 16 + ctoi(str[5]), 255);
	else if (len == 8)
		color = get_rgba(ctoi(str[2]) * 16 + ctoi(str[3]), \
			ctoi(str[4]) * 16 + ctoi(str[5]), \
			ctoi(str[6]) * 16 + ctoi(str[7]), 255);
	else if (len == 10)
		color = get_rgba(ctoi(str[2]) * 16 + ctoi(str[3]), \
			ctoi(str[4]) * 16 + ctoi(str[5]), ctoi(str[6]) * 16 + ctoi(str[7]), \
			ctoi(str[8]) * 16 + ctoi(str[9]));
	return (color);
}

//Creates a new vertex object in map.
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

//Goes through the vertex list of map and frees each.
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
	if (first)
		free(first);
}
