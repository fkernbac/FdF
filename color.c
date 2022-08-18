/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:41:41 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/15 16:29:10 by fkernbac         ###   ########.fr       */
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
	int	len;
	int	color;

	color = 0xFFFFFFFF;
	if (str == NULL)
		return (color);
	len = ft_strlen(str);
	if (str[0] != '0' && str[1] != 'x')
		perror("Color format error");
	if (len == 4)
		color = get_rgba(0, 0, ctoi(str[2]) * 16 + ctoi(str[3]), 255);
	else if (len == 6)
		color = get_rgba(0, ctoi(str[2]) * 16 + ctoi(str[3]), ctoi(str[4]) * 16 + ctoi(str[5]), 255);
	else if (len == 8)
		color = get_rgba(ctoi(str[2]) * 16 + ctoi(str[3]), ctoi(str[4]) * 16 + ctoi(str[5]), ctoi(str[6]) * 16 + ctoi(str[7]), 255);
	else if (len == 10)
		color = get_rgba(ctoi(str[2]) * 16 + ctoi(str[3]), ctoi(str[4]) * 16 + ctoi(str[5]), ctoi(str[6]) * 16 + ctoi(str[7]), ctoi(str[8]) * 16 + ctoi(str[9]));
	return (color);
}
