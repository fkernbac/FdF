/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:37:35 by fkernbac          #+#    #+#             */
/*   Updated: 2022/09/02 15:52:49 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Draws vertical up, vertical down, and horizontal right lines.
void	draw_orthogonal(t_vert *start, t_vert *end, int delta_x, int delta_y)
{
	int	x;
	int	y;

	x = start->x;
	y = start->y;
	while (delta_x == 0 && delta_y > 0 && y <= end->y)
	{
		pixelcheck(x, y, start->color, start->map->img);
		y++;
	}
	while (delta_x == 0 && delta_y < 0 && y >= end->y)
	{
		pixelcheck(x, y, start->color, start->map->img);
		y--;
	}
	while (delta_y == 0 && x <= end->x)
	{
		pixelcheck(x, y, start->color, start->map->img);
		x++;
	}
}

//Draws diagonal lines from left to right.
void	draw_diagonal(t_vert *start, t_vert *end, int sign)
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
		pixelcheck(x, y, start->color, start->map->img);
	}
}

//Draws lines to right down.
void	bresenham_low(t_vert *start, t_vert *end, int delta_x, int delta_y)
{
	int	x;
	int	y;
	int	error;
	int	step;

	x = start->x;
	y = start->y;
	error = -delta_x;
	step = 1;
	if (start->y > end->y)
		step = -1;
	while (x != end->x)
	{
		pixelcheck(x, y, start->color, start->map->img);
		x++;
		error += 2 * delta_y;
		if (error > 0)
		{
			y += step;
			error -= 2 * delta_x;
		}
	}
}

//Draws lines to right up.
void	bresenham_high(t_vert *start, t_vert *end, int delta_x, int delta_y)
{
	int	x;
	int	y;
	int	error;
	int	step;

	x = start->x;
	y = start->y;
	error = -delta_y;
	step = 1;
	if (start->y > end->y)
		step = -1;
	while (y != end->y)
	{
		pixelcheck(x, y, start->color, start->map->img);
		y += step;
		error += 2 * delta_x;
		if (error > 0)
		{
			x++;
			error -= 2 * delta_y;
		}
	}
}

//Decides if the line is up/down, a perfect diagonal,
//or anything between (bresenham algorithm).
void	draw_line(t_vert *start, t_vert *end)
{
	int	delta_x;
	int	delta_y;

	delta_x = end->x - start->x;
	delta_y = end->y - start->y;
	if (delta_x == 0 || delta_y == 0)
		draw_orthogonal(start, end, delta_x, delta_y);
	else if (delta_y == delta_x || delta_y == delta_x * -1)
		draw_diagonal(start, end, delta_y / delta_x);
	else
	{
		delta_x = abs(delta_x);
		delta_y = abs(delta_y);
		if (delta_y < delta_x)
			bresenham_low(start, end, delta_x, delta_y);
		else if (delta_y > delta_x)
			bresenham_high(start, end, delta_x, delta_y);
	}
}
