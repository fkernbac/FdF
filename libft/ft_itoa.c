/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:54:33 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:11:10 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counts the digits of n including sign
static int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

//calculates characters and fills given string
static char	*int_to_string(int n, char *string)
{
	int		i;
	int		position;

	i = 0;
	position = 1000000000;
	if (n < 0)
	{
		string[i] = '-';
		n *= -1;
		i++;
	}
	while (position > 0)
	{
		while (position > n)
			position = position / 10;
		string[i] = n / position % 10 + 48;
		position = position / 10;
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*string;

	digits = count_digits(n);
	if (digits <= 0)
		return (NULL);
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	string = malloc(digits + 1);
	if (string == NULL)
		return (NULL);
	int_to_string(n, string);
	return (string);
}
