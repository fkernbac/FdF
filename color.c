/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:41:41 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/01 17:55:46 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ctoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

int	str_to_color(char *str)
{
	int	r;
	int	g;
	int	b;
	int	a;

	if (str[0] != '0' && str[1] != 'x')
		exit(0);
	r = ctoi(str[2]) * 16 + ctoi(str[3]);
	g = ctoi(str[4]) * 16 + ctoi(str[5]);
	b = ctoi(str[6]) * 16 + ctoi(str[7]);
	if (str[8] == '\0' || str[9] == '\0')
		a = 255;
	else
		a = ctoi(str[8]) * 16 + ctoi(str[9]);
	return (get_rgba(r, g, b, a));
}
