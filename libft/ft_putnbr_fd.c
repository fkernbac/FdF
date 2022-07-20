/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:10:05 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:12:23 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//converts normalized int to char and writes to output
static void	write_positive_int(int n, int fd)
{
	int		position;
	char	ascii;

	position = 1000000000;
	while (position != 0)
	{
		while (position > n)
			position = position / 10;
		ascii = n / position % 10 + 48;
		position = position / 10;
		write(fd, &ascii, 1);
	}
}

//converts int n to string and writes to output fd
void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n <= -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	write_positive_int(n, fd);
}
