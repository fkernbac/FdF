/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:57 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/05 15:44:37 by fkernbac         ###   ########.fr       */
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
# define DEPTH 0.3
# define ZOOM 2
# define SQUISH 0.6

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
	int					rev;
	int					transp;
	struct s_vertex		*highest;
	struct s_vertex		*deepest;
	struct mlx_image	*img;
	struct mlx_image	*inactive_img;
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

//input parsing
t_map	*read_map(int fd);
int		str_to_color(char *str, t_map *map);
void	setup_map(t_map *map);
//vertex list
t_vert	*new_vertex(int x, int y, int z, t_map *map);
void	delete_list(t_map *map);
//map formatting
t_map	*init_map(void);
void	connect_vertices(t_map *map);
void	set_original(t_map *map);
void	set_height(t_map *map);
void	squish_map(t_map *map);
//line algorithms
void	draw_line(t_vert *start, t_vert *end);
void	draw_grid(t_map *map);
//FdF features
void	zoom(t_map *map, int level);
void	calc_zoom(t_map *map, int factor);
void	rotate(t_map *map, int dir);
void	create_perspective(t_map *map);
void	draw_rev_grid(t_map *map);
void	add_transparency(t_map *map);
//mlx
int		pixelcheck(int x, int y, uint32_t color, mlx_image_t *img);
void	keyhook(mlx_key_data_t keydata, void *param);
void	img_update(t_map *map);
//memory management
char	**free_split(char **split);
void	terminate(t_map *map);
void	error(int e, t_map *map);
//testing
void	print_coordinates(t_map *map);
void	draw_image(t_map *map);
void	draw_coordinates(t_map *map);

#endif
