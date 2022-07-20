/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:07:01 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 16:04:24 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks if character is a digit
int	ft_isdigit(int character)
{
	if (ft_isascii(character) == 0)
		return (0);
	if ((unsigned char) character >= (unsigned char) '0'
		&& (unsigned char) character <= (unsigned char) '9')
		return (1);
	return (0);
}
