/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:55:39 by fkernbac          #+#    #+#             */
/*   Updated: 2022/05/22 01:40:53 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts the digits of n
static int	count_digits(unsigned int n)
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

//calculates characters and fills given string for n > 0
static char	*uint_to_hexstring(unsigned int n, char *string)
{
	unsigned int	i;
	unsigned int	position;
	unsigned int	digit;

	i = 0;
	position = 268435456;
	while (position > n)
		position /= 16;
	while (position > 0)
	{
		digit = n / position % 16;
		if (digit <= 9)
			string[i] = digit + '0';
		else
			string[i] = digit - 10 + 'A';
		position = position / 16;
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_hextoa(unsigned int n, char x)
{
	int		digits;
	char	*string;
	int		i;

	if (x != 'X' && x != 'x')
		return (NULL);
	digits = count_digits(n);
	if (digits <= 0)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	string = malloc(digits + 1);
	if (string == NULL)
		return (NULL);
	uint_to_hexstring(n, string);
	if (x == 'x')
	{
		i = 0;
		while (string[i] != '\0')
		{
			string[i] = ft_tolower(string[i]);
			i++;
		}
	}
	return (string);
}
