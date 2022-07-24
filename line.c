/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:37:35 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/24 17:43:41 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//REMOVE
#include <stdio.h>

#include "FdF.h"

void	draw_diagonal(t_vert *start, t_vert *end, int sign, mlx_image_t *img)
{
	int	x;
	int	y;

	x = start->x;
	y = start->y;
	while (x < end->x)
	{
		x++;
		if (sign == 1)
			y++;
		else
			y--;
		mlx_put_pixel(img, x, y, 0xFFFF00FF);
	}
}

//steile linien nach unten (-> oben) funktionieren nicht
void	draw_bresenham(t_vert *start, t_vert *end, int up, mlx_image_t *img)
{
	int	x;
	int	y;
	int	error;
	int	delta_x;
	int	delta_y;

	delta_x = end->x - start->x;
	delta_y = end->y - start->y;
	x = start->x;
	y = start->y;
	//flach
	if (abs(delta_y < abs(delta_x)))
	{
		error = -abs(delta_x);
		while (x <= end->x)
		{
			mlx_put_pixel(img, x, y, 0xFF00FFFF);
			x++;
			error += 2 * abs(delta_y);
			if (error > 0)
			{
				y += up;
				error -= 2 * delta_x;
			}
		}
	}
	//steil
	else
	{
		error = -abs(delta_y);
		while (y <= end->y)
		{
			mlx_put_pixel(img, x, y, 0xFF00FFFF);
			y += up;
			error += 2 * abs(delta_x);
			if (error > 0)
			{
				x++;
				error -= 2 * abs(delta_y);
			}
		}
	}


	// 	delta_x = end->x - start->x;
	// delta_y = end->y - start->y;
	// x = start->x;
	// y = start->y;
	// error = sign;
	// error = 0;
	// while (x <= end->x)
	// {
	// 	mlx_put_pixel(img, x, y, 0xFF00FFFF);
	// 	x++;
	// 	error += 2 * delta_y;
	// 	if (error > delta_x)
	// 	{
	// 		y++;
	// 		error -= 2 * delta_x;
	// 	}
	// }
}

void	draw_line(t_vert *start, t_vert *end, mlx_image_t *img)
{
	int	slope;

	slope = end->y - start->y;
	// if (slope == 1 || slope == -1)
	// 	draw_diagonal(start, end, slope, img);
	// else
	if (end->y > start->y)
		draw_bresenham(start, end, 1, img);
	else
		draw_bresenham(start, end, -1, img);
}
