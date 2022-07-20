/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:53:12 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/02 23:53:12 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns int value of given clean string
long	ft_atoi(const char *string)
{
	int		i;
	long	value;
	int		sign;

	sign = 1;
	value = 0;
	i = 0;
	while (string[i] == ' ' || (string[i] >= 9 && string[i] <= 15))
		i++;
	if (string[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		value = (value * 10) + string[i] - '0';
		i++;
	}
	value = value * sign;
	return (value);
}
