/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:01 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 16:11:38 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks if character is printable
int	ft_isprint(int character)
{
	if (ft_isascii(character) == 0)
		return (0);
	if ((unsigned char) character >= ' ' && (unsigned char) character <= '~')
		return (1);
	return (0);
}
