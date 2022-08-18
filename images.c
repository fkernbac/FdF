/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:08:15 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/15 19:53:07 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	pixelcheck(int x, int y, uint32_t color, mlx_image_t *img)
{
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (0);
	mlx_put_pixel(img, x, y, color);
	return (1);
}

