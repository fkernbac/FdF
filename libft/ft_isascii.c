/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:16:36 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 16:10:59 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//checks if character is in ASCII range
int	ft_isascii(int character)
{
	if (character >= 0 && character <= 127)
		return (1);
	return (0);
}
