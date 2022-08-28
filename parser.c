/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:21:18 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/28 19:26:20 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*remove_newline(char *str)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n')
			str[i] = '\0';
	if (str[0] == '\0')
		free_and_null(str);
	return (str);
}

void	str_to_lst(t_map *map, char *string, int x, int y)
{
	char	**colorsplit;

	string = remove_newline(string);
	if (string == NULL)
		return ;
	colorsplit = ft_split(string, ',');
	if (colorsplit == NULL)
		error(2, map);
	if (colorsplit && colorsplit[0] && x == 0 && y == 0)
	{
		map->first = new_vertex(x, y, ft_atoi(colorsplit[0]), map);
		map->first->prev = NULL;
		map->last = map->first;
	}
	else if (colorsplit && colorsplit[0])
	{
		map->last->next = new_vertex(x, y, ft_atoi(colorsplit[0]), map);
		map->last->next->prev = map->last;
		map->last = map->last->next;
	}
	if (colorsplit && colorsplit[0] && colorsplit[1])
		map->last->color = str_to_color(colorsplit[1]);
	free(string);
	if (colorsplit)
		free_split(colorsplit);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		error(2, NULL);
	map->top_right = NULL;
	map->bottom_left = NULL;
	map->deepest = 0;
	map->first = NULL;
	map->highest = 0;
	map->img = NULL;
	map->img2 = NULL;
	map->instance = 0;
	map->last = NULL;
	map->mlx = NULL;
	map->zoom = 0;
	return (map);
}

t_map	*read_map(int fd)
{
	char	*line;
	char	**split;
	t_map	*map;
	int		x;
	int		y;

	x = -1;
	y = 0;
	map = init_map();
	while (1)
	{
		line = get_next_line(fd, READ_SIZE);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		if (split == NULL)
			error(2, map);
		free(line);
		while (split[++x] != NULL)
			str_to_lst(map, split[x], x, y);
		x = -1;
		y++;
		free(split);
	}
	return (map);
}
