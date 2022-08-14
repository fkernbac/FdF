/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:21:18 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/14 18:21:50 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*remove_newline(char *str)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			str[i] = '\0';
			i++;
	}
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
	if (colorsplit && colorsplit[0] && x == 0 && y == 0)
	{
		map->first = new_vertex(x, y, ft_atoi(colorsplit[0]), colorsplit[1], NULL);
		map->last = map->first;
	}
	else if (colorsplit && colorsplit[0])
	{
		map->last->next = new_vertex(x, y, ft_atoi(colorsplit[0]), colorsplit[1], map->last);
		map->last = map->last->next;
	}
	free(string);
	if (colorsplit)
		free_split(colorsplit);
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
	map = ft_calloc(1, sizeof(t_map));
	map->zoom = 0;
	map->corner_r = NULL;
	map->corner_l = NULL;
	while (1)
	{
		line = get_next_line(fd, READ_SIZE);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		free(line);
		while (split[++x] != NULL)
			str_to_lst(map, split[x], x, y);
		x = -1;
		y++;
		free(split);
	}
	return (map);
}
