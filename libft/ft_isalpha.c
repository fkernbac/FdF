/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:05:36 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 15:59:53 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks if character is alphabetical
int	ft_isalpha(int character)
{
	if (ft_isascii(character) == 0)
		return (0);
	if (((unsigned char) character >= (unsigned char) 'A'
			&& (unsigned char) character <= (unsigned char) 'Z')
		|| ((unsigned char) character >= (unsigned char) 'a'
			&& (unsigned char) character <= (unsigned char) 'z'))
		return (1);
	return (0);
}
