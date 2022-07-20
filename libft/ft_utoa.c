/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:20:35 by fkernbac          #+#    #+#             */
/*   Updated: 2022/05/22 01:40:26 by fkernbac         ###   ########.fr       */
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
		n /= 10;
		len++;
	}
	return (len);
}

//calculates characters and fills given string
static char	*uint_to_string(unsigned int n, char *string)
{
	unsigned int	i;
	unsigned int	position;

	i = 0;
	position = 1000000000;
	while (position > n)
		position /= 10;
	while (position > 0)
	{
		string[i] = n / position % 10 + '0';
		position = position / 10;
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_utoa(unsigned int n)
{
	int		digits;
	char	*string;

	digits = count_digits(n);
	if (digits <= 0)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	string = malloc(digits + 1);
	if (string == NULL)
		return (NULL);
	uint_to_string(n, string);
	return (string);
}
