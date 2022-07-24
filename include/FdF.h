/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:57 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/24 16:31:29 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"

typedef struct s_map
{
	int				f_zoom;
	int				f_height;
	int				x_max;
	int				y_max;
	struct s_vertex	*first;
	struct s_vertex	*last;
}					t_map;

typedef struct s_vertex
{
	int				x;
	int				y;
	int				z;
	int				row;
	int				col;
	struct s_vertex	*next;
	struct s_vertex	*prev;
	struct s_vertex	*left;
	struct s_vertex	*right;
	struct s_vertex	*up;
	struct s_vertex	*down;
}					t_vert;

//structs
t_vert	*new_vertex(int x, int y, int z, t_vert *left);
void	connect_vertices(t_map *map);
//graphics
void	draw_line(t_vert *start, t_vert *end, mlx_image_t *img);

#endif
