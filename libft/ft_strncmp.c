/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:29:53 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 14:51:07 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns difference of the first different characters in size chars
int	ft_strncmp(const char *a, const char *b, size_t size)
{
	size_t	i;
	int		difference;

	difference = 0;
	i = 0;
	while (i < size)
	{
		difference = ((unsigned char) a[i] - (unsigned char) b[i]);
		if (difference != 0)
			return (difference);
		if ((unsigned char) a[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
