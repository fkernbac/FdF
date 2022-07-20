/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:48:17 by fkernbac          #+#    #+#             */
/*   Updated: 2022/04/19 18:16:03 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//applies function f to each character inside original string
void	ft_striteri(char *string, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (string == NULL)
		return ;
	while (string[i] != 0)
	{
		f(i, &string[i]);
		i++;
	}
}
