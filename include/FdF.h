/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:57 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/09 19:04:38 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdio.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# define READ_SIZE 50
# define WIDTH 900
# define HEIGHT 900
# define DEPTH 0.05
# define ZOOM 2

typedef struct s_map
{
	int					zoom;
	struct mlx_image	*img;
	int					instance;
	struct mlx			*mlx;
	struct s_vertex		*first;
	struct s_vertex		*row_end;
	struct s_vertex		*col_end;
	struct s_vertex		*last;
	struct s_vertex		*highest;
	struct s_vertex		*deepest;
}						t_map;

typedef struct s_vertex
{
	int				x;
	int				y;
	int				z;
	int				xo;
	int				yo;
	int				zo;
	int				row;
	int				col;
	uint32_t		color;
	struct s_map	*map;
	struct s_vertex	*next;
	struct s_vertex	*prev;
	struct s_vertex	*left;
	struct s_vertex	*right;
	struct s_vertex	*up;
	struct s_vertex	*down;
}					t_vert;

//structs
t_map	*read_map(int fd);
t_vert	*new_vertex(int x, int y, int z, char *color, t_vert *left);
void	connect_vertices(t_map *map);
void	set_original(t_map *map);
int		str_to_color(char *str);
void	get_height(t_map *map);
//graphics
void	draw_line(t_vert *start, t_vert *end);
void	standard_zoom(t_map *map);
void	zoom(t_map *map, int in);
void	translate(t_map *map, int x, int y);
void	draw_grid(t_map *map);
//transform
void	zoom(t_map *map, int in);
void	center_map(t_map *map);
//mlx
int		pixelcheck(int x, int y, uint32_t color, mlx_image_t *img);
void	hook(void *param);
void	keyhook(mlx_key_data_t keydata, void *param);
void	update_image(t_map *map, int in);
//utilities
void	print_coordinates(t_map *map);

#endif
