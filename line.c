/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:37:35 by fkernbac          #+#    #+#             */
/*   Updated: 2022/07/20 18:05:03 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	draw_bresenham(t_vert *start, t_vert *end, int sign, mlx_image_t *img)
{
	int	x;
	int	y;
	int	error;
	int	delta_x;
	int	delta_y;

	//low
	x = start->x;
	y = start->y;
	delta_x = end->x - start->x;
	delta_y = end->y - start->y;
	sign = 1;
	if (delta_y < 0)
	{
		sign = -1;
		delta_y *= -1;
	}
	error = 2 * delta_y - delta_x;
	while (x < end->x)
	{
		if (error > 0)
		{
			y += sign;
			error += 2 * (delta_y - delta_x);
		}
		else
			error += 2 * delta_y;
		x++;


	// x = start->x;
	// y = start->y;
	// delta_x = end->x - start->x;
	// delta_y = abs(end->y - start->y);
	// error = delta_x + delta_y;
	// while (x < end->x)
	// {
	// 	if (2 * error >= delta_y)
	// 	{
	// 		error += delta_y;
	// 		x++;
	// 	}
	// 	if (2 * error >= delta_x)
	// 	{
	// 		error += delta_x;
	// 		y += sign;
	// 	}
		mlx_put_pixel(img, x, y, 0xFFFF00FF);
	}
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
