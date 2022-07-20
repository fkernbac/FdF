/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:53:52 by fkernbac          #+#    #+#             */
/*   Updated: 2022/05/22 01:39:49 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts the digits of n
static int	count_digits(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

//calculates characters and fills given string
static char	*ulong_to_hexstring(unsigned long n, char *string)
{
	unsigned int	i;
	unsigned long	position;
	unsigned long	digit;

	i = 0;
	position = 1152921504606846976;
	while (position > n)
		position /= 16;
	while (position > 0)
	{
		digit = n / position % 16;
		if (digit <= 9)
			string[i] = digit + '0';
		else
			string[i] = digit - 10 + 'a';
		position = position / 16;
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_ptoa(unsigned long n)
{
	int		digits;
	char	*string;

	if (n == 0)
		return (ft_strdup("0x0"));
	digits = count_digits(n);
	string = malloc(digits + 3);
	if (string == NULL)
		return (NULL);
	string[0] = '0';
	string[1] = 'x';
	ulong_to_hexstring(n, string + 2);
	return (string);
}
