/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:57 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/18 16:20:25 by fkernbac         ###   ########.fr       */
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
	struct s_vertex		*highest;
	struct s_vertex		*deepest;
	struct mlx_image	*img;
	int					instance;
	struct mlx			*mlx;
	struct s_vertex		*first;
	struct s_vertex		*corner_r;
	struct s_vertex		*corner_l;
	struct s_vertex		*last;
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
void	zoom(t_map *map, int in);
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

#endif
