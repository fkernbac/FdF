/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:47:22 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/01 17:56:18 by fkernbac         ###   ########.fr       */
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
	if (color != NULL)
		new->color = str_to_color(color);
	else
		new->color = 0xFFFFFFFF;
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

void	str_to_lst(t_map *map, char *string, int x, int y)
{
	char	**colorsplit;

	colorsplit = ft_split(string, ',');
	if (colorsplit == NULL)
		exit(0);
	if (x == 0 && y == 0)
	{
		map->first = new_vertex(x, y, ft_atoi(colorsplit[0]), colorsplit[1], NULL);
		map->last = map->first;
		return ;
	}
	map->last->next = new_vertex(x, y, ft_atoi(colorsplit[0]), colorsplit[1], map->last);
	map->last = map->last->next;
	free(string);
}

t_map	*read_map(int fd)
{
	char	*line;
	char	**split;
	t_map	*map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = ft_calloc(1, sizeof(t_map));
	map->zoom = 0;
	map->row_end = NULL;
	map->col_end = NULL;
	while (1)
	{
		line = get_next_line(fd, 10);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		free(line);
		if (split == NULL)
			return (NULL);
		while (split[x] != NULL)
		{
			str_to_lst(map, split[x], x, y);
			x++;
		}
		x = 0;
		y++;
		free(split);
	}
	return (map);
}

void	set_original(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		current->xo = current->x;
		current->yo = current->y;
		current->zo = current->z;
		current = current->next;
	}
}
