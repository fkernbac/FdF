/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:12:12 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 16:12:43 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//checks if character is alphanumeric
int	ft_isalnum(int character)
{
	if (ft_isascii(character) == 0)
		return (0);
	if (ft_isalpha(character) == 1 || ft_isdigit(character) == 1)
		return (1);
	return (0);
}
