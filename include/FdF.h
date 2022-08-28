/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:57 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/28 19:25:47 by fkernbac         ###   ########.fr       */
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
# define DEPTH 0.5
# define ZOOM 2
# define SQUISH 0.5

typedef struct s_map
{
	int					zoom;
	int					rotation;
	int					height;
	int					width;
	int					height_o;
	int					width_o;
	int					max_z;
	int					min_z;
	struct s_vertex		*highest;
	struct s_vertex		*deepest;
	struct mlx_image	*img;
	struct mlx_image	*img2;
	int					instance;
	struct mlx			*mlx;
	struct s_vertex		*first;
	struct s_vertex		*top_right;
	struct s_vertex		*bottom_left;
	struct s_vertex		*last;
	struct s_map		*perspective;
}						t_map;

typedef struct s_vertex
{
	int				x;
	int				y;
	int				z;
	int				xo;
	int				yo;
	int				xtop;
	int				ytop;
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
t_vert	*new_vertex(int x, int y, int z, t_map *map);
void	connect_vertices(t_map *map);
void	set_original(t_map *map);
int		str_to_color(char *str);
void	get_height(t_map *map);
void	setup_map(t_map *map);
void	delete_list(t_map *map);
//graphics
void	draw_line(t_vert *start, t_vert *end);
void	standard_zoom(t_map *map);
void	zoom(t_map *map, int level);
void	translate(t_map *map, int x, int y);
void	draw_grid(t_map *map);
//transform
void	zoom(t_map *map, int in);
void	set_height(t_map *map);
void	rotate(t_map *map, int dir);
//mlx
int		pixelcheck(int x, int y, uint32_t color, mlx_image_t *img);
void	hook(void *param);
void	keyhook(mlx_key_data_t keydata, void *param);
void	update_image(t_map *map, int in);
//utilities
void	print_coordinates(t_map *map);
char	**free_split(char **split);
void	terminate(t_map *map);
void	error(int e, t_map *map);
void	draw_image(t_map *map);
void	squish_map(t_map *map);
void	set_original(t_map *map);
void	update_image(t_map *map, int in);
void	measure_map(t_map *map);
void	calc_zoom(t_map *map, int factor);
//extra perspective
void	perspective(t_map *map);

#endif
